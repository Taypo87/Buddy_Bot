#include <stdio.h>
#include </usr/include/libevdev-1.0/libevdev/libevdev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define DEAD_ZONE 8000
#define SENSITIVITY_THRESHOLD 30000
#define LEEWAY 10000


int main(void)
{
    int fd;
    struct libevdev *dev = NULL;
    int rc = 1;

    fd = open("/dev/input/event5", O_RDONLY, O_NONBLOCK);
    if (fd < 0)
    {
        perror("Failed to open device");
        return (1);
    }
    rc = libevdev_new_from_fd(fd, &dev);
    if (rc < 0)
    {
        fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
        return (1);
    }
     rc = libevdev_new_from_fd(fd, &dev);
    if (rc < 0) {
        fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
        return 1;
    }

    printf("Input device name: \"%s\"\n", libevdev_get_name(dev));

    // Read events
    do {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
        if (rc == 0) {
            // Check the left stick position
            if (ev.type == EV_ABS) {
                static int x_value = 32768; // Center position
                static int y_value = 32768; // Center position

                if (ev.code == ABS_X) {
                    x_value = ev.value;
                } else if (ev.code == ABS_Y) {
                    y_value = ev.value;
                }

                // Determine the direction based on the vector (x_value, y_value)
                if (x_value < 32768 - SENSITIVITY_THRESHOLD && abs(y_value - 32768) < LEEWAY) {
                    printf("Turn left\n");
                } else if (x_value > 32768 + SENSITIVITY_THRESHOLD && abs(y_value - 32768) < LEEWAY) {
                    printf("Turn right\n");
                } else if (y_value < 32768 - SENSITIVITY_THRESHOLD) {
                    printf("Move forward\n");
                } else if (y_value > 32768 + SENSITIVITY_THRESHOLD) {
                    printf("Move backward\n");
                } else if (abs(x_value - 32768) < DEAD_ZONE && abs(y_value - 32768) < DEAD_ZONE) {
                    printf("Stop\n");
                }
            }
        }
    } while (rc == 1 || rc == 0 || rc == -EAGAIN);

    // Clean up
    libevdev_free(dev);
    close(fd);
}
