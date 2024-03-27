from distutils.core import setup, Extension

spi_module = Extension('spi_module', sources=['python_mods.c'])

setup(
    name='spi_module',
    version='1.0',
    description='Python SPI Module',
    ext_modules=[spi_module]
)
