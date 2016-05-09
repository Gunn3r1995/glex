#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <glm/ext.hpp>

#include "common.h"

class Camera {
        public:

                Camera();
	        glm::mat4 UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y);
	        void CollisionDetection(glm::vec3 BB_Max, glm::vec3 BB_Min);
	        glm::vec3 GetCameraPosition();
   
        private:
                
                //////////////////////////////////////////////////////////////////////////////////////////
                /// Camera Variables.
                /// Camera Variables Controls Speed of Play/Camera
                /// Controls the distance each movement moves by
                /// Sets where the starting positions of the camera 
                /// and the direction it is looking at
                //////////////////////////////////////////////////////////////////////////////////////////

                float Mouse_Sensitivity;
                float Player_Speed;

                float Camera_Horizontal;
                float Camera_Vertical;

	        float mouseDeltaX;
	        float mouseDeltaY;

                glm::vec3 Camera_Position; //= glm::vec3(0.0f,0.0f,0.0f); //Camera_BB_Max, Camera_BB_Min;

                glm::vec3 Movement_Z;
                glm::vec3 Movement_X;
                
};
#endif // CAMERA_H
