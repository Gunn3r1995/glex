#include "Camera.h"
#include <glm/ext.hpp>
#include <iostream>
#include "GameAsset.h"

using namespace std;

Camera::Camera(){

        glm::vec3 Camera_Position = glm::vec3(-0, -2, -0);

	direction = glm::vec3(0,0,0);
	right = glm::vec3(0,0,0);
	up = glm::vec3(0,0,0);

	Camera_Horizontal = 0.0;
	Camera_Vertical = 0.0;

	Camera_Delta_X = 0.0;
	Camera_Delta_Y = 0.0;

	Camera_Sensitivity = 0.1;

        //Player_Speed = 1.0;

}

glm::mat4 Camera::CameraUpdate(Movement movement, int Mouse_X, int Mouse_Y,){

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Camera Direction
        ///  Calculates the distance each camera movement changes the camera direction
        //////////////////////////////////////////////////////////////////////////////////////////
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

        if(movement == UP ){
                cout << "UP" << endl;
                camera_position += glm::vec3(cos(vertical_angle) * sin(horizontal_angle),
				0, cos(vertical_angle) * cos(horizontal_angle)) * camera_movement_speed;

        }

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Projection matrix. : degree = 45, Field of View = 4:3 ratio, display = 0.1 unit <-> 1000 units
        //////////////////////////////////////////////////////////////////////////////////////////
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 1000.0f);
        // Where the Camera Looks at
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

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Send data to Uniform Variable.
        /// Sends the data to the translate.vs shader
        //////////////////////////////////////////////////////////////////////////////////////////
	glUniformMatrix4fv(0, 1, GL_FALSE, &Camera_Projection[0][0]);
	glUniformMatrix4fv(1, 1, GL_FALSE, &Camera_View[0][0]);
	glUniformMatrix4fv(2, 1, GL_FALSE, &Camera_Model[0][0]);



}
/*

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Camera Direction
        ///  Calculates the distance each camera movement changes the camera direction
        //////////////////////////////////////////////////////////////////////////////////////////
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
        /// Projection matrix. : degree = 45, Field of View = 4:3 ratio, display = 0.1 unit <-> 1000 units
        //////////////////////////////////////////////////////////////////////////////////////////
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 1000.0f);
        // Where the Camera Looks at
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

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Send data to Uniform Variable.
        /// Sends the data to the translate.vs shader
        //////////////////////////////////////////////////////////////////////////////////////////
	glUniformMatrix4fv(0, 1, GL_FALSE, &Camera_Projection[0][0]);
	glUniformMatrix4fv(1, 1, GL_FALSE, &Camera_View[0][0]);
	glUniformMatrix4fv(2, 1, GL_FALSE, &Camera_Model[0][0]);

*/
