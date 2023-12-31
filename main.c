#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
/* #include <SDL2/SDL2_gfxPrimitives.h> */
#include "lib/snake.h"
#include "lib/consts.h"
#include "lib/food.h"

int quit = 0;

int main(void) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    printf("Initializing SDL... %d\n", SDL_Init(SDL_INIT_VIDEO));

    window = SDL_CreateWindow("Csnake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    struct Snake snake;
    struct Food food;

    init_game(&snake);
    generate_food_pos(&food);

    SDL_Event event;
    while (!quit) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_food(&food, renderer);

        render_snake(renderer, &snake);
        handle_movement(&snake);
        check_eat_food(&snake, &food);

        if (check_collisions(&snake)) {
            break;
        }

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            const Uint8 *state = SDL_GetKeyboardState(NULL);

            if (event.type == SDL_QUIT || state[SDL_SCANCODE_Q]) {
                quit = 1;
            }

            if (state[SDL_SCANCODE_UP] && snake.direction != DIRECTION_DOWN) {
                snake.direction = DIRECTION_UP;
            }

            else if (state[SDL_SCANCODE_DOWN] && snake.direction != DIRECTION_UP) {
                snake.direction = DIRECTION_DOWN;
            }

            else if (state[SDL_SCANCODE_LEFT] && snake.direction != DIRECTION_RIGHT) {
                snake.direction = DIRECTION_LEFT;
            }

            else if (state[SDL_SCANCODE_RIGHT] && snake.direction != DIRECTION_LEFT) {
                snake.direction = DIRECTION_RIGHT;
            }
        }

        SDL_Delay(120);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
