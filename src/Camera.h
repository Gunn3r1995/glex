#ifndef CAMERA_H
#define CAMERA_H

using namespace std;

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/gl.h>
#else
#   error "Unknown compiler"
#endif

#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>
#include <memory>

#include "GameAsset.h"
#include "common.h"

class Camera {
        public:

                Camera();
	        glm::mat4 UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y);

                float GetLeftBoundingBox();
                float GetRightBoundingBox();
                float GetTopBoundingBox();
                float GetBottomBoundingBox();
                float GetFrontBoundingBox();
                float GetBackBoundingBox();     
        private:
                
                //////////////////////////////////////////////////////////////////////////////////////////
                /// Camera Variables.
                /// Camera Variables Controls Speed of Play/Camera
                /// Controls the distance each movement moves by
                /// Sets where the starting positions of the camera 
                /// and the direction it is looking at
                //////////////////////////////////////////////////////////////////////////////////////////

                GLfloat Mouse_Sensitivity;
                GLfloat Player_Speed;

                GLfloat Camera_Horizontal;
                GLfloat Camera_Vertical;

	        float mouseDeltaX;
	        float mouseDeltaY;

                glm::vec3 Camera_Position;
                glm::vec3 Camera_Old_Position = Camera_Position;

                glm::vec3 Movement_Z;
                glm::vec3 Movement_X;
                
};
#endif // CAMERA_H
