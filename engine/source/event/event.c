#include <stdio.h>

#include "../../include/engine.h"



int processEvents(SDL_Event event) {
	if (SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_QUIT:
				gameLoop = 0;
				break;
			default:
				break;


		}
	} 
}