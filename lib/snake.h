#ifndef SNAKE_H
#define SNAKE_H

#define SPEED 10
#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

#define SNAKE_HEAD_R 255
#define SNAKE_HEAD_G 0
#define SNAKE_HEAD_B 0

#define SNAKE_TAIL_R 0
#define SNAKE_TAIL_G 255
#define SNAKE_TAIL_B 0

struct Position {
    int x;
    int y;
};

struct Tail {
    struct Position pos;
};

struct Snake {
    struct Position pos;
    int direction;
    int width, height;
    int size;
    struct Tail *tail;
};

void init_game(struct Snake *snake);
void render_snake(struct SDL_Renderer *renderer, struct Snake *snake);
void handle_movement(struct Snake *snake);
int check_collisions(struct Snake *snake);

#endif // !SNAKE_H
