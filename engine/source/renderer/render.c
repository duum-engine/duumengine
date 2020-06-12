#include "../../include/engine.h"

int render() {
	SDL_GL_SwapWindow(window);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

