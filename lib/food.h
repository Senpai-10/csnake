#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

struct Food {
    int x;
    int y;
};

void generate_food_pos(struct Food *food);
void render_food(struct Food *food, struct SDL_Renderer *renderer);
void check_eat_food(struct Snake *snake, struct Food *food);

#endif // !FOOD_H
