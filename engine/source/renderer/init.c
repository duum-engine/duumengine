#include "../../include/engine.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_GLContext context;

bool fullscreen = false;

float vertices[18] = {
    -0.5f,  0.5f, 1.0f, // Top-left
     0.5f,  0.5f, 0.0f, // Top-right
     0.5f, -0.5f, 0.0f, // Bottom-right

     0.5f, -0.5f, 0.0f, // Bottom-right
    -0.5f, -0.5f, 1.0f, // Bottom-left
    -0.5f,  0.5f, 1.0f  // Top-left
};



shader fragmentShaderCode;

shader vertexShaderCode;

GLuint vertexShader;
GLuint fragmentShader;
GLuint shaderProgram;
GLint posAttrib;

GLuint vao;
GLuint VBO;



int initRender() {
	logtofile("initialising renderer!", INF);
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

	logtofile("Initialising GLEW", INF);
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		sprintf(error, "GLEW initialisation failure, error: %s\n", glewGetErrorString(err));
		logtofile(error, SVR);
		return 1;
	}

	createVAO();

	createVBO();

	if (loadShaders() == 1) {
		return 1;
	}

	if (compileShaders() == 1) {
		return 1;
	}

	initTransformations();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	logtofile("finished initialising renderer by some miracle!!", INF);
	return 0;
}



int createVAO() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

}

int createVBO() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int loadShaders() {
	logtofile("loading shaders!", INF);
	FILE *fileptr;
	GLchar **code;
	fileptr = fopen("engine/res/shaders/shader.vs", "r");
	if (fileptr == NULL) {
		logtofile("vertex shader code cannot be found! this is bad :(", ERR);
		return 1;
	}

	loadLines(fileptr, &vertexShaderCode);

	fileptr = fopen("engine/res/shaders/shader.fs", "r");
	if (fileptr == NULL) {
		logtofile("fragment shader code cannot be found! this is bad :(", ERR);
		return 1;
	}

	loadLines(fileptr, &fragmentShaderCode);

	return 0;
}

shader loadLines(FILE* file, shader* shader) {
	int chunksize = 256;


	shader->code = malloc(sizeof(GLchar*));
	shader->code[0] = malloc(sizeof(GLchar) * chunksize);
	shader->lineCount = 0;

	while(fgets(shader->code[shader->lineCount], chunksize, file) != NULL) {
		shader->lineCount++;
		shader->code = realloc(shader->code, sizeof(GLchar*) * (shader->lineCount + 1));
		shader->code[shader->lineCount] = malloc(sizeof(GLchar) * chunksize);
	}
}


int compileShaders() {
	logtofile("Compiling shaders", INF);
	GLint status;


	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, vertexShaderCode.lineCount, (const GLchar**)vertexShaderCode.code, NULL);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, fragmentShaderCode.lineCount, (const GLchar**)fragmentShaderCode.code, NULL);

	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		logtofile("Vertex shader compiling failure, error:", SVR);
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		logtofile(buffer, ERR);
		return 1;
	}

	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		logtofile("Fragment shader compiling failure, error:", SVR);
		char buffer[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
		logtofile(buffer, ERR);
		return 1;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);
	

	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);


	return 0;
}

/*

    GL_STATIC_DRAW: The vertex data will be uploaded once and drawn many times (e.g. the world).
    GL_DYNAMIC_DRAW: The vertex data will be created once, changed from time to time, but drawn many times more than that.
    GL_STREAM_DRAW: The vertex data will be uploaded once and drawn once.


*/
