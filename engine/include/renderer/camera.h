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
int viewMatrix();
int projectionMatrix();

mat4 model;
GLint uniModel;

mat4 view;
GLint uniView;

vec3 eye;
vec3 center;
vec3 up;

mat4 proj;
GLint uniProj;