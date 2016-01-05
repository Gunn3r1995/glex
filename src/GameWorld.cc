#include "GameWorld.h"

using namespace std;
// Credit http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/ 
GLfloat camera_speed = 0.1;

		GLfloat camera_x = 0.0;
		GLfloat camera_y = 0.0;

glm::vec3 Camera_Position = glm::vec3(0, 0, 0);
glm::vec3 Movement_Z;
glm::vec3 Movement_X;

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
        cout << "Key W Pressed" << endl;
        Camera_Position =  Camera_Position + Movement_Z;
 }
  if ( key == 'a' ) {        // A Key Pressed will move Camera left
        cout << "Key A Pressed" << endl;
        Camera_Position = Camera_Position - Movement_X;
 }
  if ( key == 's' ) {        // S Key Pressed will move Camera down
        cout << "Key S Pressed" << endl;
        Camera_Position = Camera_Position - Movement_Z;
 }
  if ( key == 'd' ) {        // D Key Pressed will move Camera right
        cout << "Key D Pressed" << endl;
        Camera_Position = Camera_Position + Movement_X;
 }
  if (key == '^') {
		camera_y += 0.5f * 0.05;
 }
  if (key == '<') {
		camera_x += 0.5f * 0.05;
 }
  if (key == 'v') {
		camera_y -= 0.5f * 0.05;
 }
  if (key == '>') {
		camera_x -= 0.5f * 0.05;
 }
}

void GameWorld::Draw() {
        asset_manager->Draw();

        glm::vec3 direction(
		cos(camera_y) * sin(camera_x),
		sin(camera_y),
		cos(camera_y) * cos(camera_x)
	);

	glm::vec3 Movement_Direction(
		1 * 0,
		0,
		1 * 1
	);
	Movement_Z = Movement_Direction;

	Movement_X = glm::vec3(
		sin(0.0 - 3.14f/2.0f),
		0,
		cos(0.0 - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(Movement_X, direction);
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
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
