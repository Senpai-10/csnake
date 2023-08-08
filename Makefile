FILES=main.c lib/snake.c lib/food.c
FLAGS=-lSDL2 -lm
EXE=csnake

build:
	gcc ${FILES} -o ${EXE} ${FLAGS}

run: build
	./${EXE}
