#ifndef CAMERA_H
#define CAMERA_H

using namespace std;


#include <iostream>
#include <string>
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
                float Mouse_Sensitivity, Player_Speed, Camera_Horizontal, Camera_Vertical, mouseDeltaX, mouseDeltaY;

                glm::vec3 Camera_Position, Camera_BB_Max, Camera_BB_Min, Movement_Z, Movement_X;
                string ControlSave;
                
};
#endif // CAMERA_H
