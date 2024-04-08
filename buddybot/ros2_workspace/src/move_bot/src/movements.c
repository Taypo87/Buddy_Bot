#include "../include/move_bot/spi.h"
#include <string.h>

static int spi_fd = -1;
uint8_t  mode = 0;      // Example SPI mode
uint32_t speed = 1000000;           // Example SPI speed (1 MHz) ?? CHECK SPEED COMPATABILITY ??
uint8_t bits = 8;                 // Example number of bits per word
int spi_open() {

    // Open SPI device
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        perror("Failed to open SPI device");
        return 1;
    }

    // Configure SPI mode, bits per word, and speed
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("Failed to configure SPI device");
        close(spi_fd);
        return 1;
    }

    return 0;
}

int get_spi_fd()
{
    return(spi_fd);
}

int spi_close() {
    return close(spi_fd);
}

int move_forward(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = FORWARD;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int move_back(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = BACKWARD;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int move_left(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = LEFT;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int move_right(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = RIGHT;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int drift_left(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = DRIFT_L;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int drift_right(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 3;
    packet.command = DRIFT_R;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}

int move_stop(int spi_fd) {
    cmd_packet_t packet;
    ssize_t bytes_written;

    packet.speed = 0;
    packet.command = STOP;
    if (spi_fd < 0) {
        fprintf(stderr, "SPI connection not initialized.\n");
        return -1;
    }
    bytes_written = write(spi_fd, &packet, sizeof(packet));
    if (bytes_written < 0) {
        perror("Failed to write command packet to SPI device");
        return -1;
    }

    return 0;
}