#include "spi.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"

static int spi_fd = -1;
uint8_t mode = 0;      // Example SPI mode
uint32_t speed = 1000000;           // Example SPI speed (1 MHz) ?? CHECK SPEED COMPATABILITY ??
uint8_t bits = 8;                 // Example number of bits per word

// Define function prototypes with correct signatures
static PyObject* spi_open(PyObject* self, PyObject* args);
static PyObject* spi_close(PyObject* self, PyObject* args);
static PyObject* move_forward(PyObject* self, PyObject* args);
static PyObject* move_back(PyObject* self, PyObject* args);
static PyObject* move_left(PyObject* self, PyObject* args);
static PyObject* move_right(PyObject* self, PyObject* args);
static PyObject* drift_left(PyObject* self, PyObject* args);
static PyObject* drift_right(PyObject* self, PyObject* args);
static PyObject* move_stop(PyObject* self, PyObject* args);


// Method definition object for this extension
static PyMethodDef SpiModuleMethods[] = {
    {"spi_open", spi_open, METH_NOARGS, "Open SPI device"},
    {"spi_close", spi_close, METH_NOARGS, "Close SPI device"},
    {"move_forward", move_forward, METH_NOARGS, "Move forward"},
    {"move_back", move_back, METH_NOARGS, "Move backward"},
    {"move_left", move_left, METH_NOARGS, "Move left"},
    {"move_right", move_right, METH_NOARGS, "Move right"},
    {"drift_left", drift_left, METH_NOARGS, "Drift left"},
    {"drift_right", drift_right, METH_NOARGS, "Drift right"},
    {"move_stop", move_stop, METH_NOARGS, "Stop movement"},
    {NULL, NULL, 0, NULL}
};



// Module definition
static struct PyModuleDef spi_module = {
    PyModuleDef_HEAD_INIT,
    "spi_module",  // Name of the module
    NULL,          // Module documentation
    -1,            // Size of pre-interpreter state of the module
    SpiModuleMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_spi_module(void) {
    return PyModule_Create(&spi_module);
}


static PyObject* spi_open(PyObject* self, PyObject* args) {
    // Open SPI device
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "Failed to open SPI device");
        return NULL;
    }

    // Configure SPI mode, bits per word, and speed
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        PyErr_SetString(PyExc_IOError, "Failed to configure SPI device");
        close(spi_fd);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* spi_close(PyObject* self, PyObject* args) {
    if (close(spi_fd) < 0) {
        PyErr_SetString(PyExc_IOError, "Failed to close SPI device");
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject* move_forward(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = FORWARD;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* move_back(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = BACKWARD;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* move_left(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = LEFT;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* move_right(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = RIGHT;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* drift_left(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = DRIFT_L;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* drift_right(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = DRIFT_R;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject* move_stop(PyObject* self, PyObject* args) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    // Initialize packet
    packet.speed = 3;
    packet.command = STOP;

    // Check if SPI connection is initialized
    if (spi_fd < 0) {
        PyErr_SetString(PyExc_IOError, "SPI connection not initialized.");
        return NULL;
    }

    // Write command packet to SPI device
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        PyErr_SetFromErrno(PyExc_IOError);
        return NULL;
    }

    Py_RETURN_NONE;
}
