#include "../../include/engine.h"

SDL_Window* window;
SDL_Renderer* renderer;

int initRender() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL Init failure, error: %s\n", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow("SDL Game Engine", 100, 100, WIDTH, HEIGHT, 0);
	if (window == NULL) {
		printf("SDL window creation, error: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("SDL renderer creation, error: %s\n", SDL_GetError());
		return 1;
	}
	return 0;
}