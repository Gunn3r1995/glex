#ifndef CAMERA_H
#define CAMERA_H

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
	        void CollisionDetection(glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos);
   
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

                glm::vec3 Movement_Z;
                glm::vec3 Movement_X;
                
};
#endif // CAMERA_H
