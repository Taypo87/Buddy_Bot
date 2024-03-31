#include <stdio.h>
#include </usr/include/libevdev-1.0/libevdev/libevdev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd;
    struct libevdev *dev = NULL;
    int rc = 1;

    // Open the device
    fd = open("/dev/input/event5", O_RDONLY|O_NONBLOCK);
    if (fd < 0) {
        perror("Failed to open device");
        return 1;
    }

    rc = libevdev_new_from_fd(fd, &dev);
    if (rc < 0) {
        fprintf(stderr, "Failed to init libevdev (%s)\n", strerror(-rc));
        return 1;
    }

    printf("Input device name: \"%s\"\n", libevdev_get_name(dev));

    // Initialize the state of the stick
    int stick_vertical = 0; // 0 = neutral, 1 = up, -1 = down
    int stick_horizontal = 0; // 0 = neutral, 1 = right, -1 = left

    // Read events
    do {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
        if (rc == 0) {
            // Check the left stick vertical position
            if (ev.type == EV_ABS && ev.code == ABS_Y) {
                if (ev.value < 128) {
                    if (stick_vertical != 1) {
                        printf("Move forward\n");
                        stick_vertical = 1;
                    }
                } else if (ev.value > 128) {
                    if (stick_vertical != -1) {
                        printf("Move backward\n");
                        stick_vertical = -1;
                    }
                } else {
                    if (stick_vertical != 0) {
                        printf("Stop\n");
                        stick_vertical = 0;
                    }
                }
            }

            // Check the left stick horizontal position
            if (ev.type == EV_ABS && ev.code == ABS_X) {
                if (ev.value < 128) {
                    if (stick_horizontal != -1) {
                        printf("Turn left\n");
                        stick_horizontal = -1;
                    }
                } else if (ev.value > 128) {
                    if (stick_horizontal != 1) {
                        printf("Turn right\n");
                        stick_horizontal = 1;
                    }
                } else {
                    if (stick_horizontal != 0) {
                        stick_horizontal = 0;
                        printf("Stop\n");
                    }
                }
            }
        }
    } while (rc == 1 || rc == 0 || rc == -EAGAIN);

    // Clean up
    libevdev_free(dev);
    close(fd);

    return 0;
}