#pragma once
#define INIT_RENDERER_ENGINE_H

int initRender();

SDL_Window* window;
SDL_Renderer* renderer;
SDL_GLContext context;

bool fullscreen;


int createVAO();
int createVBO();
int loadShaders();
int compileShaders();

float vertices[18];

typedef struct {
	GLchar** code;
	int lineCount;
} shader;

shader loadLines(FILE* file, shader* shader);

shader fragmentShaderCode;
shader vertexShaderCode;

GLuint vertexShader;
GLuint fragmentShader;
GLuint shaderProgram;
GLint posAttrib;

GLuint vao;
GLuint VBO;