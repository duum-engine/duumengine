#include "../../include/engine.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_GLContext context;


int initRender() {
	char* error;
	logtofile("Starting SDL", INF);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		sprintf(error, "SDL Init failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
<<<<<<< Updated upstream
=======
		return 1;
	}

	logtofile("Starting SDL Audio system", INF);
	if (audioerror == 1) {
		sprintf(error, "SDL Audio Init failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
>>>>>>> Stashed changes
		return 1;
	}

	logtofile("Creating window", INF);
	window = SDL_CreateWindow("SDL Game Engine", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		sprintf(error, "SDL window creation failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

	logtofile("Creating renderer", INF);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		sprintf(error, "SDL renderer creation failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
<<<<<<< Updated upstream
		return 1;
	}

	logtofile("Creating OpenGL context", INF);
	context = SDL_GL_CreateContext(window);
	if (context == NULL) {
		sprintf(error, "GL context creation failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

=======
		return 1;
	}

	logtofile("Creating OpenGL context", INF);
	context = SDL_GL_CreateContext(window);
	if (context == NULL) {
		sprintf(error, "GL context creation failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

>>>>>>> Stashed changes
	logtofile("Initialising GLEW", INF);
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		sprintf(error, "GLEW initialisation failure, error: %s\n", glewGetErrorString(err));
		logtofile(error, SVR);
		return 1;
	}

	/*GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	printf("%u\n", vertexBuffer);*/

	return 0;
}