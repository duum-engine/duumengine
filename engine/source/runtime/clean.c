#include "../../include/engine.h"

int cleanEngine() {

	SDL_GL_DeleteContext(context);
	logtofile("Destroying OpenGL context", INF);

	SDL_DestroyRenderer(renderer);
	logtofile("Destroying renderer", INF);

	SDL_DestroyWindow(window);
	logtofile("Destroying window", INF);

	

	TTF_Quit();
	SDL_Quit();
}