#include "../../include/engine.h"

int gameLoop = 1;



int main(int argc, char* argv[]) {
	int framerate = 60;
	int d;

	initLog();
	if (initRender() == 1) {
		cleanEngine();
		return 0;
	}

	startaudio();

	//startaudio();


	while (gameLoop) {
		
		SDL_Event event;

		processEvents(event);

		render();

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	SDL_SetWindowFullscreen(window, 0);

		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
		if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_f && d == 0) {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            d = 0;
            SDL_Delay(1000);
		} 
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) {
            SDL_SetWindowFullscreen(window, 0);
        }
		else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_f && d == 1) {
            SDL_SetWindowFullscreen(window, 0);
            d = 1;
            SDL_Delay(1000);
        }
	}}




	cleanEngine();
	logtofile("closing window", INF);

	return 0;
}
