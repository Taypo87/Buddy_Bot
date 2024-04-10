#ifndef _SPI_H_
#define _SPI_H_

#include <Python.h>
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

// int spi_open();
// int spi_close();
// int move_forward(int spi_fd);
// int move_back(int spi_fd);
// int move_left(int spi_fd);
// int move_right(int spi_fd);
// int drift_left(int spi_fd);
// int drift_right(int spi_fd);
// int move_stop(int spi_fd);
// int get_spi_fd();
// Function prototypes
static PyObject* spi_open(PyObject* self, PyObject* args);
static PyObject* spi_close(PyObject* self, PyObject* args);
static PyObject* move_forward(PyObject* self, PyObject* args);
static PyObject* move_back(PyObject* self, PyObject* args);
static PyObject* move_left(PyObject* self, PyObject* args);
static PyObject* move_right(PyObject* self, PyObject* args);
static PyObject* drift_left(PyObject* self, PyObject* args);
static PyObject* drift_right(PyObject* self, PyObject* args);
static PyObject* move_stop(PyObject* self, PyObject* args);

#endif