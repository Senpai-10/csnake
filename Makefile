FILES=main.c lib/snake.c
FLAGS=-lSDL2 -lm
EXE=csnake

build:
	gcc ${FILES} -o ${EXE} ${FLAGS}

run: build
	./${EXE}
