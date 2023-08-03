build:
	gcc main.c -o csnake -lSDL2

run: build
	./csnake
