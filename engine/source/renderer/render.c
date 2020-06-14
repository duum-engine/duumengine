#include "../../include/engine.h"

int render() {
	SDL_GL_SwapWindow(window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

