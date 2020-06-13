#include "../../include/engine.h"



int transform(int axis) {
	mat4 trans;
	glm_mat4_identity(trans);
	glm_rotate_z(trans, 180.0f, trans);
	/*GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, (const GLfloat*)trans);*/
}

