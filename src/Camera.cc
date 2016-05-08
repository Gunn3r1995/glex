#include "Camera.h"
#include "GameAssetManager.h"

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////
/// Controls calculations
/// Controls all the movement and positions of the camera 
/// Uses keyboard and Mouse movements to move around the world space
/// Tells the Camera matrix what position to look at and where to move
//////////////////////////////////////////////////////////////////////////////////////////
Camera::Camera() {
          Camera_Position = glm::vec3(0.0f, 0.0f, 0.0f);

	  Camera_Horizontal = 0.0f;
	  Camera_Vertical = 0.0f;

          mouseDeltaX = 0.0;
	  mouseDeltaY = 0.0;

	  Player_Speed = 0.5; 
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Drawing the world.
/// Draws the assets to the world by calling GameAssetManager
/// Sends the camera positions and movements to the translate shader
//////////////////////////////////////////////////////////////////////////////////////////
glm::mat4 Camera::UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y) {
        //////////////////////////////////////////////////////////////////////////////////////////
        /// Camera Direction
        ///  Calculates the distance each camera movement changes the camera direction
        //////////////////////////////////////////////////////////////////////////////////////////
        // mouse delta position inverted
	mouseDeltaX = -Mouse_X;
	mouseDeltaY = -Mouse_Y;

        Camera_Horizontal += 0.001f * mouseDeltaX;

        if((Camera_Vertical + (0.01f * mouseDeltaY)) < 3.0f && (Camera_Vertical + (0.01f * mouseDeltaY)) > -3.0f ){
	        Camera_Vertical += 0.001f * mouseDeltaY;
        }

        glm::vec3 direction(
		cos(Camera_Vertical) * sin(Camera_Horizontal),
		sin(Camera_Vertical),
		cos(Camera_Vertical) * cos(Camera_Horizontal)
	);
        
	Movement_Z = direction;

	Movement_X = glm::vec3(
		sin(Camera_Horizontal - 3.14f/2.0f),
		0,
		cos(Camera_Horizontal - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(Movement_X, direction);
        
        //////////////////////////////////////////////////////////////////////////////////////////
        ///Keyboard Input Use
        ///This gets the Current Control State and then calculates the appropriate changes to the 
        ///Camera Position.
        //////////////////////////////////////////////////////////////////////////////////////////
        if(control == UP) {
		Camera_Position +=  Movement_Z * Player_Speed;
	}
        else if(control == DOWN) {
		Camera_Position -= Movement_Z * Player_Speed;
	} 
        else if(control == LEFT) {
		Camera_Position -= Movement_X * Player_Speed;
	} 
        else if(control == RIGHT) {
		Camera_Position += Movement_X * Player_Speed;
	}
        else if(control == JUMP) {
                Camera_Position.y += 0.5f * Player_Speed;
        }
        else if(control == CROUCH) {
                Camera_Position.y -= 0.5f * Player_Speed;
        }
        else if(control == PRINT) {
                cout << "********************************************************************" << endl;
                cout << "Camera Position: " << glm::to_string(Camera_Position) << endl;
                //cout << "Camera Old Position: " << glm::to_string(Camera_Old_Position) << endl;
                
                cout << "Camera Axis Alligned Bounding Box" << endl;
                cout << "********************************************************************" << endl;
        }


        //////////////////////////////////////////////////////////////////////////////////////////
        ///  Camera view matrix.
        ///  changes where the camera position looks up to use the camera position
        ///  changes the direction you look at
        ///  Makes the world the correct orientation
        //////////////////////////////////////////////////////////////////////////////////////////
        return glm::lookAt(Camera_Position, 
                           Camera_Position + direction, 
                           vup);
   
}

/*void Camera::CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos) {
       glm::vec3 camera_bounding_box_max = Camera_Position += glm::vec3(1.0,1.0,1.0);
       glm::vec3 camera_bounding_box_min = Camera_Position += glm::vec3(-1.0,-1.0,-1.0);
        //Camera_BB_Max = Camera_Position += glm::vec3(0.5f,1.5f,0.5f);
        //Camera_BB_Min = Camera_Position += glm::vec3(0.5f,1.5f,0.5f);
        //cout << "BB2 Max: " << glm::to_string(BB2_Max) << endl;
        //cout << "BB2 Min: " << glm::to_string(BB2_Min) << endl;
        //cout << "BB2 Pos: " << glm::to_string(BB2_Pos) << endl;

}*/
