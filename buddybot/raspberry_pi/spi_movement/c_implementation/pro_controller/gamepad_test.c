#include </usr/include/SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    if (SDL_NumJoysticks() < 1) {
        fprintf(stderr, "No joysticks connected!\n");
        return 1;
    }

    SDL_Joystick *joystick = SDL_JoystickOpen(0);
    if (joystick == NULL) {
        fprintf(stderr, "Failed to open joystick: %s\n", SDL_GetError());
        return 1;
    }

    printf("Number of axes: %d\n", SDL_JoystickNumAxes(joystick));
    printf("Number of buttons: %d\n", SDL_JoystickNumButtons(joystick));

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto cleanup;
            } else if (event.type == SDL_JOYBUTTONDOWN) {
                printf("Button %d pressed\n", event.jbutton.button);
            } else if (event.type == SDL_JOYBUTTONUP) {
                printf("Button %d released\n", event.jbutton.button);
            }
        }
    }

cleanup:
    SDL_JoystickClose(joystick);
    SDL_Quit();
    return 0;
}
