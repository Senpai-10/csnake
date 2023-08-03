#include <stdio.h>
#include <SDL2/SDL.h>
/* #include <SDL2/SDL2_gfxPrimitives.h> */

const int WIDTH = 800;
const int HEIGHT = 800;

int quit = 0;

int main(void) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    printf("Initializing SDL... %d\n", SDL_Init(SDL_INIT_VIDEO));

    window = SDL_CreateWindow("Csnake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event;
    while (!quit) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            const Uint8 *state = SDL_GetKeyboardState(NULL);

            if (event.type == SDL_QUIT || state[SDL_SCANCODE_Q]) {
                quit = 1;
            }
        }
        SDL_Delay(120);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
