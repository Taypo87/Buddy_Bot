#include "spi.h"
#include <string.h>

#define INPUT_SIZE  10


int main()
{
    int fd;
    char command[10];
    
    spi_open();
    fd = get_spi_fd();
    while (1)
    {
        printf("Awaiting Command!\n");
        fgets(command , 10, stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "forward") == 0)
            move_forward(fd);
        else if (strcmp(command, "backward") == 0)
            move_back(fd);
        else if (strcmp(command, "left") == 0)
            move_left(fd);
        else if (strcmp(command, "right") == 0)
            move_right(fd);
        else if (strcmp(command, "dright") == 0)
            drift_right(fd);
        else if (strcmp(command, "dleft") == 0)
            drift_left(fd);
        else if (strcmp(command, "stop") == 0)
            move_stop(fd);
        else
        {
            printf("Command not recognized! The commands are as follows.\n");
            printf("forward\nbackward\nleft\nright\ndright\ndleft\nstop\n");
        }
    }
}