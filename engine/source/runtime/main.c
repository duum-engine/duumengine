#include "../../include/engine.h"

int gameLoop = 1;



int main(int argc, char* argv[]) {
	int framerate = 60;

	initLog();
	if (initRender() == 1) {
		cleanEngine();
		return 0;
	}


	//startaudio();
	loadOBJ("engine/res/models/Link Adult.obj");

	while (gameLoop) {	
		SDL_Event event;

		processEvents(event);

		transform();

		render();

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}




	cleanEngine();
	logtofile("closing window", INF);

	return 0;
}
