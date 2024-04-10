from setuptools import setup

package_name = 'mpu'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Taylor Poczynek',
    maintainer_email='taylor.poczynek87@gmail.com',
    description='ROS package for interfacing with MPU6050 sensor',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mpu_publisher = mpu.mpupublisher:main',
            'mpu_subscriber = mpu.mpusubscriber:main',
        ],
    },
)
