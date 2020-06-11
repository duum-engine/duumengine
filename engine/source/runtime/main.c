#include <stdio.h>

#include "../../include/engine.h"

int gameLoop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;

	if (initRender() == 1) {
		return 0;
	}

	while (gameLoop) {
		
		SDL_Event event;

		processEvents(event);

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}

	SDL_Quit();


	return 0;
}
