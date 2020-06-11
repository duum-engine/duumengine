#include "../../include/engine.h"

int gameLoop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;

	initLog();

	if (initRender() == 1) {
		return 0;
	}

	

	while (gameLoop) {
		
		SDL_Event event;

		processEvents(event);

		render();

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}

	

	cleanEngine();

	return 0;
}
