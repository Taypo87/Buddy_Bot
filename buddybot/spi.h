#ifndef _SPI_H_
#define _SPI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"  // Example SPI device
#define MODE       SPI_MODE_0        // Example SPI mode
#define SPEED      1000000           // Example SPI speed (1 MHz)
#define BITS       8                 // Example number of bits per word




#endif