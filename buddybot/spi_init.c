#include "spi.h"

uint8_t  mode = 0;      // Example SPI mode
uint32_t speed = 1000000;           // Example SPI speed (1 MHz)
uint8_t bits = 8;                 // Example number of bits per word
int main() {
    int spi_fd;
    uint8_t tx_data[] = {0x01, 0x02, 0x03};  // Example data to transmit
    uint8_t rx_data[sizeof(tx_data)];       // Buffer to store received data

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

    // Perform SPI transfer
    if (write(spi_fd, tx_data, sizeof(tx_data)) != sizeof(tx_data)) {
        perror("Failed to write data to SPI device");
        close(spi_fd);
        return 1;
    }
    if (read(spi_fd, rx_data, sizeof(rx_data)) != sizeof(rx_data)) {
        perror("Failed to read data from SPI device");
        close(spi_fd);
        return 1;
    }

    // Display received data
    printf("Received data:");
    for (int i = 0; i < sizeof(rx_data); i++) {
        printf(" 0x%02X", rx_data[i]);
    }
    printf("\n");

    // Close SPI device
    close(spi_fd);

    return 0;
}

