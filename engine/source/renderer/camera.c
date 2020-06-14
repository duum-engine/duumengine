#include "../../include/engine.h"

mat4 model;

GLint uniModel;

int initTransformations() {
	//creates model matrix
	glm_mat4_identity(model);
	uniModel = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, (const GLfloat*)model);
	
}

int transform() {
	modelMatrix();
	//view();
	//projection();
}

int modelMatrix() {
	glm_rotate_z(model, 0.1f, model);
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, (const GLfloat*)model);
}


