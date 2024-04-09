import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32  # Use Int32 to publish the distance
import serial
import time

class TFminiSNode(Node):
    def __init__(self):
        super().__init__('tfmini_s_node')
        self.publisher_ = self.create_publisher(Int32, 'tfmini_s_distance', 10)
        self.timer = self.create_timer(0.05, self.read_distance)  # Adjust the timer as needed

        # Set up the serial connection
        self.ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

        # Command to request a single distance measurement
        self.request_command = b'\x5A\x05\x00\x01\x60'

    def read_distance(self):
        try:
            self.ser.write(self.request_command)
            time.sleep(0.05)
            self.ser.flushInput()
            response = self.ser.read(9)
            time.sleep(0.05)
            if len(response) >= 9:
                distance = response[2] + (response[3] << 8)
                if 0 <= distance <= 1600:
                    self.publisher_.publish(Int32(data=distance))
                    self.get_logger().info(f"Distance: {distance} cm")
            else:
                self.get_logger().warn("Incomplete response received.")
        except Exception as e:
            self.get_logger().error(f"Error: {e}")

    def __del__(self):
        if self.ser.is_open:
            self.ser.close()

def main(args=None):
    rclpy.init(args=args)
    node = TFminiSNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
