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
#define FORWARD 0x00
#define BACKWARD 0x01
#define LEFT 0x02
#define RIGHT 0x03
#define DRIFT_R 0x04
#define DRIFT_L 0x05
#define STOP 0x06

typedef struct cmd_packet_s {
    unsigned speed : 2;
    unsigned command : 6;
    } cmd_packet_t;

#endif