#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "snake.h"
#include "consts.h"
#include "distance.h"

void init_game(struct Snake *snake) {
    printf("Initializing the game\n");
    snake->width = 20;
    snake->height = 20;
    snake->pos.x = (WINDOW_WIDTH / 2) - snake->width;
    snake->pos.y = (WINDOW_HEIGHT / 2) - snake->height;
    snake->tail = malloc(sizeof(struct Tail));
    snake->size = 0;
    snake->direction = DIRECTION_LEFT;
}

void render_snake(struct SDL_Renderer *renderer, struct Snake *snake) {
    SDL_Rect rect = { snake->pos.x, snake->pos.y, snake->width, snake->height };
    SDL_SetRenderDrawColor(renderer, SNAKE_HEAD_R, SNAKE_HEAD_G, SNAKE_HEAD_B, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);

    for (int i = 0; i <= snake->size; ++i) {
        SDL_SetRenderDrawColor(renderer, SNAKE_TAIL_R, SNAKE_TAIL_G, SNAKE_TAIL_B, 255);
        SDL_Rect new_tail = { snake->tail->pos.x, snake->tail->pos.y, snake->width, snake->height };

        SDL_RenderDrawRect(renderer, &new_tail);
        SDL_RenderFillRect(renderer, &new_tail);
    }
}

void handle_movement(struct Snake * snake) {
    for (int i = 0; i <= snake->size - 2; ++i) {
        snake->tail[i] = snake->tail[i+1];
    }

    struct Tail new_tail = { snake->pos.x, snake->pos.y };
    snake->tail[snake->size - 1] = new_tail;

    switch (snake->direction) {
        case DIRECTION_UP:
            snake->pos.y -= SPEED;
            break;

        case DIRECTION_DOWN:
            snake->pos.y += SPEED;
            break;

        case DIRECTION_LEFT:
            snake->pos.x -= SPEED;
            break;

        case DIRECTION_RIGHT:
            snake->pos.x += SPEED;
            break;
    }
}

int check_collisions(struct Snake *snake) {
    if (snake->pos.x == 0 || snake->pos.y == 0 || snake->pos.x == WINDOW_WIDTH || snake->pos.y == WINDOW_HEIGHT) {
        return 1;
    }

    for (int i = 0; i <= snake->size -1; ++i) {
        int dist = distance(snake->pos.x, snake->pos.y, snake->tail[i].pos.x, snake->tail[i].pos.y);

        if (dist < 1) {
            return 1;
        }
    }

    return 0;
}

