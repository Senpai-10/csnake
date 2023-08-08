#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "consts.h"
#include "food.h"
#include "distance.h"
#include "snake.h"

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

void check_eat_food(struct Snake *snake, struct Food *food) {
    double dist = distance(snake->pos.x, snake->pos.y, food->x, food->y);

    if (dist < 1) {
        /* snake->size += 1; */
        generate_food_pos(food);
        struct Tail *temp = realloc(snake->tail, (snake->size * sizeof(struct Tail)));

        if (temp != NULL) {
            snake->tail = temp;
            struct Tail new_tail = {snake->pos.x, snake->pos.y};
            snake->tail[snake->size-1] = new_tail;
        }
    }
}
