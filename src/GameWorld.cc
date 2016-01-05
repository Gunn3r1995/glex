#include "GameWorld.h"

using namespace std;

GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){
  int pointX,pointY,pointZ;
  int worldX = 16;
  int worldY = 16;
  int world[worldY][worldX] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0},
  {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };
  pointZ = 50;
  

  for( pointX=0; pointX<worldX; pointX++){
   for (pointY=0; pointY<worldY; pointY++){
    if( world[pointY][pointX] == 1){
    asset_manager->AddAsset(std::make_shared<CubeAsset>((pointX-8),-(pointY-7),(pointZ)));
   }
  }
 } 
}

void GameWorld::Camera_Control(char key) {
  if ( key == 'w' ) {        // W Key Pressed will move Camera forward
        Camera_Position += Movement_Z * Player_Speed;
 }
  if ( key == 'a' ) {        // A Key Pressed will move Camera left
        Camera_Position -= Movement_X * Player_Speed;
 }
  if ( key == 's' ) {        // S Key Pressed will move Camera down
        Camera_Position -= Movement_Z * Player_Speed;
 }
  if ( key == 'd' ) {        // D Key Pressed will move Camera right
        Camera_Position += Movement_X * Player_Speed;
 }
  if (key == '^') {         //Camera look Up
        Camera_Vertical += 0.5f * Mouse_Sensitivity;
 }
  if (key == '<') {         //Camera look left
        Camera_Horizontal += 0.5f * Mouse_Sensitivity;
 }
  if (key == 'v') {        //Camera look down
        Camera_Vertical -= 0.5f * Mouse_Sensitivity;
 }
  if (key == '>') {        //Camera look right
        Camera_Horizontal -= 0.5f * Mouse_Sensitivity;
 }
}

void GameWorld::Draw() {
        asset_manager->Draw();

        glm::vec3 direction(
		cos(Camera_Vertical) * sin(Camera_Horizontal),
		sin(Camera_Vertical),
		cos(Camera_Vertical) * cos(Camera_Horizontal)
	);
	//Fixes camera going upside down.
        glm::vec3 Movement_Direction(
		cos(Camera_Vertical) * sin(Camera_Horizontal),
		0,
		cos(Camera_Vertical) * cos(Camera_Horizontal)
	);

	Movement_Z = Movement_Direction;


	Movement_X = glm::vec3(
		sin(Camera_Horizontal - 3.14f/2.0f),
		0,
		cos(Camera_Horizontal - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(Movement_X, direction);
        // Projection matrix : degree = 45, Field of View = 16:9 ratio, display = 0.1 unit <-> 1000 units
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
        //Where the Camera Looks at
	glm::mat4 Camera_View = glm::lookAt(
		Camera_Position,
		Camera_Position + direction,
		vup
	);
	glm::mat4 Camera_Model(1.0f);

	glUniformMatrix4fv(0, 1, GL_FALSE, &Camera_Projection[0][0]);
	glUniformMatrix4fv(1, 1, GL_FALSE, &Camera_View[0][0]);
	glUniformMatrix4fv(2, 1, GL_FALSE, &Camera_Model[0][0]);
}
