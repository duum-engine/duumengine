#pragma once
#define CAMERA_RENDER_H

enum axis {
	X_AX,
	Y_AX,
	Z_AX
};

int transform();

int initTransformations();

int modelMatrix();

mat4 model;

GLint uniModel;
