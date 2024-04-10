from setuptools import find_packages
from setuptools import setup

setup(
    name='mpu',
    version='0.0.1',
    packages=find_packages(
        include=('mpu', 'mpu.*')),
)
