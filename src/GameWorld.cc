#include "GameWorld.h"
#include "common.h"


using namespace std;

GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){
  int pointX,pointY;
  int pointZ = 1;
  int worldX = 20;
  int worldY = 20;

  /*2D array which acts like the world space for the game, so depending on what number is stored within the array 
   would change which blocks spawn within this small 20 by 20 world, I would like to improve the size of the array 
   in the future but as of now I don't think it's to important. 

   1-> 2 high Ground Blocks
   2-> A 1 high Cube with a Diamond on top
   3-> A 2 high Cube with a Diamond on top
   4-> A Tree
   5-> A Cube with a Pyramid on top
   6-> A Pyramid
   */
  int world[20][20] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,2,1,1,1,1,1,1,1,1,5,1,1,7,1,1,1,1,2,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,3,7,1,1,1,7,1,1,1,1,1,1,1,3,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,7,1,1,1,1},
  {1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,7,1,1,1,1,1,1,1,1,1,7,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,5,1,1,6,1,1,1,1,1,4,1,1,1,1,6,1,1,5,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,1,1,1,1},
  {1,1,1,1,1,1,1,7,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,1,7,1,1},
  {1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1},
  {1,1,1,1,1,1,7,1,1,1,1,1,1,7,7,1,1,1,1,1},
  {1,2,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,2,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};

        asset_manager->AddAsset(make_shared<GroundAsset>( 1.0f ,2.00f, -4.0f));
        asset_manager->AddAsset(make_shared<CubeAsset>(   3.0f ,2.00f, -4.0f));
        asset_manager->AddAsset(make_shared<LeavesAsset>( 5.0f ,2.00f, -4.0f));
        asset_manager->AddAsset(make_shared<DiamondAsset>(7.0f ,2.00f, -4.0f));
        asset_manager->AddAsset(make_shared<PyramidAsset>(9.0f ,1.50f, -4.0f)); 
  

  for( pointX=0; pointX<worldX; pointX++){
   for (pointY=0; pointY<worldY; pointY++){
    if( world[pointY][pointX] == 1){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-2.00f,(pointZ*pointY)));
   }
    else if( world[pointY][pointX] == 2){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX)  ,0.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<DiamondAsset>((pointX),1.0f,(pointZ*pointY)));
   }
    else if( world[pointY][pointX] == 3){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),0.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<DiamondAsset>((pointX),2.0f,(pointZ*pointY)));
   }
    else if( world[pointY][pointX] == 4){
            //Tree Ground
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            //Tree Trunk
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),0.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),2.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),3.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX),4.00f,(pointZ*pointY)));
            //Tree Leaves - Bottom Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),3.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),3.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,3.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),3.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),3.0f,(pointZ*pointY-1)));

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),3.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),3.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,3.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),3.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),3.0f,(pointZ*pointY-2)));

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),3.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),3.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),3.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),3.0f,(pointZ*pointY))); 

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),3.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),3.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,3.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),3.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),3.0f,(pointZ*pointY+1)));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),3.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),3.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,3.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),3.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),3.0f,(pointZ*pointY+2)));
            //Tree Leaves - Second Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),4.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),4.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,4.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),4.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),4.0f,(pointZ*pointY-1)));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),4.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),4.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,4.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),4.0f,(pointZ*pointY-2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),4.0f,(pointZ*pointY-2)));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),4.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),4.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),4.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),4.0f,(pointZ*pointY)));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),4.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),4.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,4.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),4.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),4.0f,(pointZ*pointY+1)));

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+2),4.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),4.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,4.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),4.0f,(pointZ*pointY+2)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-2),4.0f,(pointZ*pointY+2)));
            //Tree Leaves - Third Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),5.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,5.0f,(pointZ*pointY-1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),5.0f,(pointZ*pointY-1))); 

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),5.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,5.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),5.0f,(pointZ*pointY)));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),5.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,5.0f,(pointZ*pointY+1)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),5.0f,(pointZ*pointY+1)));

            //Tree Leaves - Fourth Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,6.0f,(pointZ*pointY-1)));

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX+1),6.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,6.0f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX-1),6.0f,(pointZ*pointY)));

            asset_manager->AddAsset(make_shared<LeavesAsset>((pointX)  ,6.0f,(pointZ*pointY+1)));
   }
    else if( world[pointY][pointX] == 5){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<CubeAsset>((pointX)  ,0.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<PyramidAsset>((pointX),0.50f,(pointZ*pointY)));
   }
    else if( world[pointY][pointX] == 6){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<PyramidAsset>((pointX),-0.50f,(pointZ*pointY)));
   }
    else if( world[pointY][pointX] == 7){
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GroundAsset>((pointX),-1.00f,(pointZ*pointY)));
            asset_manager->AddAsset(make_shared<GrassAsset>((pointX-Random/(rand() % 100)),(-0.50f),(pointZ*pointY-Random/(rand()%10))));            
            asset_manager->AddAsset(make_shared<GrassAsset>((pointX-Random/(rand() % 100)),(-0.30f),(pointZ*pointY-Random/(rand() % 100))));
            asset_manager->AddAsset(make_shared<GrassAsset>((pointX-Random/(rand() % 100)),(-0.45f),(pointZ*pointY-Random/(rand() % 100))));
            asset_manager->AddAsset(make_shared<GrassAsset>((pointX-Random/(rand() % 100)),(-0.50f),(pointZ*pointY-Random/(rand() % 100))));
            asset_manager->AddAsset(make_shared<GrassAsset>((pointX-Random/(rand() % 100)),(-0.20f),(pointZ*pointY-Random/(rand() % 100))));
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
  if (key == '+') {        //Jump up/ 0.1, Would like to improve it to a actually jump mechanic
        Camera_Position += 0.1f * Player_Speed;
 }
  if (key == '-') {       // Drop down/ -0.1
        Camera_Position -= 0.1f * Player_Speed;
 }
}

void GameWorld::Draw() {

        glm::vec3 direction(
		cos(Camera_Vertical) * sin(Camera_Horizontal),
		sin(Camera_Vertical),
		cos(Camera_Vertical) * cos(Camera_Horizontal)
	);
	//Fixes camera going upside down.
        glm::vec3 Movement_Direction(
		1.0f * sin(Camera_Horizontal),
		0.0f,
		1.0f * cos(Camera_Horizontal)
	);

	Movement_Z = Movement_Direction;


	Movement_X = glm::vec3(
		sin(Camera_Horizontal - 3.14f/2.0f),
		0,
		cos(Camera_Horizontal - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(Movement_X, Movement_Direction);
        // Projection matrix : degree = 45, Field of View = 4:3 ratio, display = 0.1 unit <-> 1000 units
	glm::mat4 Camera_Projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 1000.0f);
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

        asset_manager->Draw();
}
