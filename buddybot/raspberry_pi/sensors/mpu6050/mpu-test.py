#!/usr/bin/env python3

import smbus
import time

# MPU-6050 registers
PWR_MGMT_1 = 0x6B
ACCEL_XOUT_H = 0x3B
ACCEL_YOUT_H = 0x3D
ACCEL_ZOUT_H = 0x3F
GYRO_XOUT_H = 0x43
GYRO_YOUT_H = 0x45
GYRO_ZOUT_H = 0x47

def read_i2c_word(register):
    # Read two bytes of data from the register
    high = bus.read_byte_data(address, register)
    low = bus.read_byte_data(address, register + 1)
    # Combine the high and low bytes
    value = (high << 8) + low
    # Convert to signed value
    if value >= 0x8000:
        value = -(65536 - value)
    return value

bus = smbus.SMBus(1)  # Use I2C bus 1
address = 0x68  # MPU-6050 I2C address

# Wake up the MPU-6050
bus.write_byte_data(address, PWR_MGMT_1, 0)

try:
    while True:
        # Read accelerometer and gyroscope values
        accel_x = read_i2c_word(ACCEL_XOUT_H)
        accel_y = read_i2c_word(ACCEL_YOUT_H)
        accel_z = read_i2c_word(ACCEL_ZOUT_H)
        gyro_x = read_i2c_word(GYRO_XOUT_H)
        gyro_y = read_i2c_word(GYRO_YOUT_H)
        gyro_z = read_i2c_word(GYRO_ZOUT_H)

        # Print the values
        print("Accelerometer: X = {}, Y = {}, Z = {}".format(accel_x, accel_y, accel_z))
        print("Gyroscope: X = {}, Y = {}, Z = {}".format(gyro_x, gyro_y, gyro_z))

        # Wait before the next reading
        time.sleep(1)

except KeyboardInterrupt:
    print("Exiting...")