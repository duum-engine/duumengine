#include "../../include/engine.h"

mat4 model;
GLint uniModel;

mat4 view;
GLint uniView;

vec3 eye = {1.2f, 1.2f, 1.2f};
vec3 center = {0.0f, 0.0f, 0.0f};
vec3 up = {0.0f, 0.0f, 1.0f};

mat4 proj;
GLint uniProj;

int initTransformations() {
	//creates model matrix
	glm_mat4_identity(model);
	uniModel = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, (const GLfloat*)model);

	glm_lookat(eye, center, up, view);
	uniView = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, (const GLfloat*)view);

	glm_perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f, proj);
	uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, (const GLfloat*)proj);
}



int transform() {
	modelMatrix();
	viewMatrix();
	projectionMatrix();
}

int modelMatrix() {
	glm_rotate_z(model, 0.01f, model);
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, (const GLfloat*)model);
}

int viewMatrix() {
	glUniformMatrix4fv(uniView, 1, GL_FALSE, (const GLfloat*)view);
}

int projectionMatrix() {
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, (const GLfloat*)proj);
}