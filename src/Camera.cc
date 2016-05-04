#include "Camera.h"

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

          mouseDeltaX = 0.01;
	  mouseDeltaY = 0.01;

	  Player_Speed = 0.5;
          
          Old_Camera_Position = Camera_Position;  
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

        Camera_Horizontal += 0.01 * mouseDeltaX;
        // restrict the mouse view from going too far up or down
        if((Camera_Vertical + (0.01 * mouseDeltaY)) < 1 && (Camera_Vertical + (0.01 * mouseDeltaY)) > -1 ){
	        Camera_Vertical += 0.01 * mouseDeltaY;
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

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Projection matrix. : degree = 45, Field of View = 4:3 ratio, display = 0.1 unit <-> 1000 units
        //////////////////////////////////////////////////////////////////////////////////////////
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 1000.0f);
     
        //////////////////////////////////////////////////////////////////////////////////////////
        ///  Camera view matrix.
        ///  changes where the camera position looks up to use the camera position
        ///  changes the direction you look at
        ///  Makes the world the correct orientation
        //////////////////////////////////////////////////////////////////////////////////////////
	glm::mat4 Camera_View = glm::lookAt(
		Camera_Position,
		Camera_Position + direction,
		vup
	);
	glm::mat4 Camera_Model(1.0f);

        return glm::lookAt(Camera_Position, Camera_Position + direction, vup);
   
}
/*
float Camera::GetLeftBoundingBox() {
        Left = Camera_X_Position - 0.5;
        return Left;
}

float Camera::GetRightBoundingBox() {
        Right = Camera_X_Position + 0.5;
        return Right;    
}

float Camera::GetTopBoundingBox() {
        Top = Camera_Y_Position + 0.5;
        return Top;       
}
float Camera::GetBottomBoundingBox() {
        Bottom = Camera_Y_Position - 0.5;
        return Bottom;        
}
float Camera::GetFrontBoundingBox() {
        Front = Camera_Z_Position + 0.5;
        return Front; 
}
float Camera::GetBackBoundingBox() {
        Back = Camera_Z_Position - 0.5;
        return Back;        
}*/
