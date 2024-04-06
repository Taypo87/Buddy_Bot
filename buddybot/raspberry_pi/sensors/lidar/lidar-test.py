#!/usr/bin/env python3

import serial
import time

# Set up the serial connection
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

# Command to request a single distance measurement
request_command = b'\x5A\x05\x00\x01\x60'

try:
    # Send the command
    ser.write(request_command)

    # Wait a short time for the response
    time.sleep(0.1)

    # Read the response (9 bytes for TFmini-S)
    response = ser.read(9)

    # Print the raw response
    print("Raw response:", response)

    # Parse and print the distance from the response (bytes 2 and 3)
    if len(response) >= 9:
        distance = response[2] + (response[3] << 8)
        print(f"Distance: {distance} cm")
    else:
        print("Incomplete response received.")
except Exception as e:
    print(f"Error: {e}")
finally:
    ser.close()
