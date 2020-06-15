#include "../../include/engine.h"

int loadOBJ(char* filename) {
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL) {
		char error[128];
		sprintf(error, "Cannot load OBJ \"%s\"", filename);
		logtofile(error, ERR);
		return 0;
	}
	char* lineHeader[128];
	fscanf(lineHeader, "%127s", fptr);
}

