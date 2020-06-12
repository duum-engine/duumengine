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