#include "../../include/engine.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_GLContext context;

bool fullscreen = false;


int initRender() {
	char* error;
	logtofile("Starting SDL", INF);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		sprintf(error, "SDL Init failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

	logtofile("Starting SDL Audio system", INF);
	if (audioerror == 1) {
		sprintf(error, "SDL Audio Init failure, error: %s\n", SDL_GetError());
		logtofile(error, SVR);
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
		return 1;
	}

		return 1;
	}

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

	createVBO();

	if (loadShaders() == 1) {
		return 1;
	}

	if (compileShaders() == 1) {
		return 1;
	}

	return 0;
}

float vertices[6] = {
     0.0f,  0.5f, // Vertex 1 (X, Y)
     0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
};

GLuint VBO;

char fragmentShaderCode[512];
char vertexShaderCode[512];

GLuint vertexShader;
GLuint fragmentShader;

int createVBO() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int loadShaders() {
	FILE *shaderptr;
	size_t size;

	shaderptr = fopen("engine/res/shaders/shader.fs", "r");
	if (shaderptr == NULL) {
		logtofile("Fragment shader CANNOT be found! this is bad :(", SVR);
		return 1;
	}

	fread(fragmentShaderCode, 1, 512, shaderptr);

	shaderptr = fopen("engine/res/shaders/shader.vs", "r");
	if (shaderptr == NULL) {
		logtofile("Vertex shader CANNOT be found! this is bad :(", SVR);
		return 1;
	}

	fread(vertexShaderCode, 1, 512, shaderptr);


	return 0;
}

int compileShaders() {
	GLint status;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, (const GLchar**)&vertexShaderCode, NULL);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, (const GLchar**)&fragmentShaderCode, NULL);

	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		logtofile("Vertex shader compiling failure, error:", SVR);
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		logtofile(buffer, SVR);
		return 1;
	}

	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		logtofile("Fragment shader compiling failure, error:", SVR);
		char buffer[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
		logtofile(buffer, SVR);
		return 1;
	}

	return 0;
}

/*

    GL_STATIC_DRAW: The vertex data will be uploaded once and drawn many times (e.g. the world).
    GL_DYNAMIC_DRAW: The vertex data will be created once, changed from time to time, but drawn many times more than that.
    GL_STREAM_DRAW: The vertex data will be uploaded once and drawn once.


*/
