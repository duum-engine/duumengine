#include <stdio.h>

#include "../../include/engine.h"



int processEvents(SDL_Event event) {
	if (SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_QUIT:
				gameLoop = 0;
				break;

			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_f && fullscreen == true) {
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
					fullscreen = !fullscreen;
				} else if (event.key.keysym.sym == SDLK_f && fullscreen == false) {
					SDL_SetWindowFullscreen(window, 0);
					fullscreen = !fullscreen;
				}
				break;

			default:
				break;


		}
	} 
}