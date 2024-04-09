from setuptools import find_packages
from setuptools import setup

setup(
    name='move_bot',
    version='0.0.0',
    packages=find_packages(
        include=('move_bot', 'move_bot.*')),
)
