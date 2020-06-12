#include "../../include/engine.h"

int gameLoop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;

	initLog();
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
	if (initRender() == 1) {
		return 0;
	}

<<<<<<< Updated upstream
	
=======
	startaudio();
>>>>>>> Stashed changes

	while (gameLoop) {
		
		SDL_Event event;

		processEvents(event);

		render();

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}

	
<<<<<<< Updated upstream

	cleanEngine();
=======
>>>>>>> Stashed changes

	cleanEngine();
	logtofile("closing window", INF);
	
	return 0;
}
