#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/ext.hpp>
#include <vector>
#include <memory>
#include "common.h"
#include "GameAsset.h"
#include <GL/gl.h>

class Camera{

public:
  Camera();
  glm::mat4 CameraUpdate(Movement movement, int Mouse_X, int Mouse_Y);
private:

        glm::vec3 Camera_Position;

        glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

        GLfloat Camera_Horizontal;
        GLfloat Camera_Vertical;

        GLfloat Camera_Delta_X;
	GLfloat Camera_Delta_Y;

        GLfloat Camera_Sensitivity;

};

#endif // CAMERA_H_
