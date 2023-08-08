#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "consts.h"
#include "food.h"

void generate_food_pos(struct Food *food) {
    srand(time(NULL));
    int rand_x = (rand() % WINDOW_WIDTH);
    int rand_y = (rand() % WINDOW_HEIGHT);

    food->x = rand_x;
    food->y = rand_y;
}

void render_food(struct Food *food, struct SDL_Renderer *renderer) {
    SDL_Rect rect = { food->x, food->y, 20, 20 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
}
