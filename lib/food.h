#ifndef FOOD_H
#define FOOD_H

struct Food {
    int x;
    int y;
};

void generate_food_pos(struct Food *food);
void render_food(struct Food *food, struct SDL_Renderer *renderer);

#endif // !FOOD_H
