#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

def main(args=None):
	rclpy.init(args=args)  #must have this line to start the node
	node = Node("py_test")
	node.get_logger().info("Hello ROS2")
	rclpy.shutodwn()

if __name__ == "__main__":
	main()
