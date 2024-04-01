import pigpio
import DHT22
import time

# Initialize pigpio and the DHT22 sensor
pi = pigpio.pi()
sensor = DHT22.sensor(pi, 27)  # Assuming the sensor is connected to GPIO pin 4

try:
    while True:
        sensor.trigger()
        time.sleep(2)  # DHT22 requires at least 2 seconds between readings
        temperature = sensor.temperature()
        humidity = sensor.humidity()
        print(f"Temperature: {temperature:.2f}°C, Humidity: {humidity:.2f}%")
except KeyboardInterrupt:
    # Clean up
    sensor.cancel()
    pi.stop()
