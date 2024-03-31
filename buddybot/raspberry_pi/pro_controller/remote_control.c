#include </usr/include/SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define DEAD_ZONE_X 12000
#define DEAD_ZONE_Y 12000
#define SENSITIVITY_THRESHOLD_X 30000
#define SENSITIVITY_THRESHOLD_Y 30000
#define BUFFER_ZONE 6000

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Joystick *joystick = SDL_JoystickOpen(0);
    if (!joystick) {
        fprintf(stderr, "Could not open joystick: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int running = 1;
    int prevAxisValueX = 0; // Previous value of the X axis
    int prevAxisValueY = 0; // Previous value of the Y axis
    while (running) {
        SDL_JoystickUpdate(); // Update the state of the joystick

        int axisValueX = SDL_JoystickGetAxis(joystick, 0); // Get the value of the X axis
        int axisValueY = SDL_JoystickGetAxis(joystick, 1); // Get the value of the Y axis

        if (prevAxisValueX || prevAxisValueY) 
        {   
            if((abs(axisValueX) < SENSITIVITY_THRESHOLD_X - DEAD_ZONE_X - BUFFER_ZONE) &&
             (abs(axisValueY) < (SENSITIVITY_THRESHOLD_Y - DEAD_ZONE_Y - BUFFER_ZONE)))
            {
                printf("Joystick returned to neutral\n");
                prevAxisValueX = 0;
                prevAxisValueY = 0;
            }
        }
        if (axisValueX > SENSITIVITY_THRESHOLD_X && !prevAxisValueX)
        {
            prevAxisValueX = axisValueX;
            printf("Joystick moved right\n");
        } else if (axisValueX < -SENSITIVITY_THRESHOLD_X && !prevAxisValueX)
        {
            prevAxisValueX = axisValueX;
            printf("Joystick moved left\n");
        }

        if (axisValueY > SENSITIVITY_THRESHOLD_Y && !prevAxisValueY)
        {
            prevAxisValueY = axisValueY;
            printf("Joystick moved backward\n");
        } else if (axisValueY < -SENSITIVITY_THRESHOLD_Y && !prevAxisValueY)
        {
            prevAxisValueY = axisValueY;
            printf("Joystick moved forward\n");
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
