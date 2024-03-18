#include "spi.h"

#define INPUT_SIZE = 10

int main()
{
    char command[10];

    while (1)
    {
        printf("Awaiting Command!\n");
        fgets(command , 10, stdin);
        if (strcmp(command, "forward") == 0)
            move_forward(3);
        else if (strcmp(command, "backward") == 0)
            move_back(3);
        else if (strcmp(command, "left") == 0)
            move_left(3);
        else if (strcmp(command, "right") == 0)
            move_right(3);
        else if (strcmp(command, "dright") == 0)
            drift_right(3);
        else if (strcmp(command, "dleft") == 0)
            drift_left(3);
        else if (strcmp(command, "stop") == 0)
            move_stop();
        else
        {
            printf("Command not recognized! The commands are as follows.\n");
            printf("forward\nbackward\nleft\nright\ndright\ndleft\nstop\n");
        }
    }
}