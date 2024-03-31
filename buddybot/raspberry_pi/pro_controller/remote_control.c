#include </usr/include/SDL2/SDL.h>
#include "../spi.h"
#include <stdio.h>
#include <stdlib.h>

#define DEAD_ZONE_X 12000
#define DEAD_ZONE_Y 12000
#define SENSITIVITY_THRESHOLD_X 30000
#define SENSITIVITY_THRESHOLD_Y 30000
#define BUFFER_ZONE 6000

int main(int argc, char *argv[])
{
    int spifd;
    int running = 1, axisValueX, axisValueY;
    int prevAxisValueX = 0; // Previous value of the X axis
    int prevAxisValueY = 0; // Previous value of the Y axis

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Joystick *joystick = SDL_JoystickOpen(0);
    if (!joystick)
    {
        fprintf(stderr, "Could not open joystick: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    spi_open();
    spifd = get_spi_fd();

    while (running)
    {
        SDL_JoystickUpdate(); // Update the state of the joystick

        axisValueX = SDL_JoystickGetAxis(joystick, 0); // Get the value of the X axis
        axisValueY = SDL_JoystickGetAxis(joystick, 1); // Get the value of the Y axis

        if (prevAxisValueX || prevAxisValueY) 
        {   
            if((abs(axisValueX) < SENSITIVITY_THRESHOLD_X - DEAD_ZONE_X - BUFFER_ZONE) &&
             (abs(axisValueY) < (SENSITIVITY_THRESHOLD_Y - DEAD_ZONE_Y - BUFFER_ZONE)))
            {
                move_stop(spifd);
                prevAxisValueX = 0;
                prevAxisValueY = 0;
            }
        }
        if (axisValueX > SENSITIVITY_THRESHOLD_X && !prevAxisValueX)
        {
            prevAxisValueX = axisValueX;
            move_right(spifd);
        } else if (axisValueX < -SENSITIVITY_THRESHOLD_X && !prevAxisValueX)
        {
            prevAxisValueX = axisValueX;
            move_left(spifd);
        }

        if (axisValueY > SENSITIVITY_THRESHOLD_Y && !prevAxisValueY)
        {
            prevAxisValueY = axisValueY;
            move_back(spifd);
        } else if (axisValueY < -SENSITIVITY_THRESHOLD_Y && !prevAxisValueY)
        {
            prevAxisValueY = axisValueY;
            move_forward(spifd);
        }

        SDL_Delay(10); // Add a small delay to prevent the loop from running too fast


        // Check for the quit event
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_JoystickClose(joystick);
    SDL_Quit();

    return 0;
}
