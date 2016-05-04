#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager (make_shared<GameAssetManager>(mode)){
  int pointX,pointY;
  int pointZ = 1;
  int worldX = 20;
  int worldY = 20;

  //////////////////////////////////////////////////////////////////////////////////////////
  ///  2D array for world space.
  ///  2D array which acts like the world space for the game, so depending on what 
  ///  number is stored within the array would change which blocks spawn within this small 
  ///  20 by 20 world, I would like to improve the size of the array in the future but as of
  ///  now I don't think it's to important. 
  ///
  ///  1-> 2 high Ground Blocks.
  ///
  ///  2-> A 1 high Cube with a Diamond on top.
  ///
  ///  3-> A 2 high Cube with a Diamond on top.
  ///
  ///  4-> A Tree.
  ///
  ///  5-> A Cube with a Pyramid on top.
  ///
  ///  6-> A Pyramid.
  ///
  ///  7-> Somewhat Random Grass.
  //////////////////////////////////////////////////////////////////////////////////////////
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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };
        
  //////////////////////////////////////////////////////////////////////////////////////////
  /// Spawning different Voxels.
  /// Spawns all the Voxel assets I made just outside the array space,
  /// Just so you can view each voxel on it's own.
  /// Each of them has random animations or changes to them to show off the animation. 
  //////////////////////////////////////////////////////////////////////////////////////////

        asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3(1.0f ,2.00f, -4.0f),
                                                         glm::vec3(0.0f,0.0f,0.0f), false,
                                                         No_Rotation, false,
                                                         Double_Size, true));
        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3(3.0f ,2.00f, -4.0f),
                                                       glm::vec3(0.0f,0.0f,0.0f), false,
                                                       Fast_Rotation, true,
                                                       Normal_Size, false));
        asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3(5.0f ,2.00f, -4.0f),
                                                         glm::vec3(0.0f,0.0f,0.0f), false,
                                                         glm::vec3(0.1f,0.1f,0.1f), true,
                                                         glm::vec3(1.1f,1.1f,1.1f), true));
        asset_manager->AddAsset(make_shared<DiamondAsset>(Spawn, glm::vec3(7.0f ,2.0f, -4.0f),
                                                          glm::vec3(7.0f, 2.0f, 0.0f), true,
                                                          No_Rotation, false,
                                                          Normal_Size, false));
        asset_manager->AddAsset(make_shared<PyramidAsset>(Spawn, glm::vec3(9.0f ,1.50f, -4.0f),
                                                          glm::vec3(0.0f,0.0f,0.0f), false,
                                                          No_Rotation, false,
                                                          Double_Size, false)); 
        asset_manager->AddAsset(make_shared<GrassAsset>(Spawn, glm::vec3(11.0f,1.50f, -4.0f), 
                                                        glm::vec3(0.0f,0.0f,0.0f), false,
                                                        No_Rotation, false,
                                                        Giant_Size, true));

   /////////////////////////////////////////////////////////////////////////////////////////
   //AddAsset Layout 
   //This adds the asset to the game asset manager which draws it to the screen
   //
   //  asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, Translate
   //                                                 AnimateTo , Bool,
   //                                                 Rotation, Bool,
   //                                                 Scale, Bool));  
   /////////////////////////////////////////////////////////////////////////////////////////

  for( pointX=0; pointX<worldX; pointX++){
   for (pointY=0; pointY<worldY; pointY++){
    if( world[pointY][pointX] == 1){          
            ////////////////////////////////////////////////////////////////////////////////////////// 
            ///  Spawns Ground.
            ///  Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-2.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false ));
   }
    else if( world[pointY][pointX] == 2){
            ////////////////////////////////////////////////////////////////////////////////////////// 
            ///  Spawning Small Diamond Tower.
            ///  Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            ///  Spawns the Cube & Diamond asset on top to create a small tower with a diamond on top
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),0.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Double_Size, true));
            asset_manager->AddAsset(make_shared<DiamondAsset>(Spawn, glm::vec3((pointX),1.0f,(pointZ*pointY)), 
                                                              glm::vec3((pointX)+10.0f,1.0f+10.0f,(pointZ*pointY)+10.0f), true,
                                                              Normal_Rotation, true,
                                                              Normal_Size, false));
   }
    else if( world[pointY][pointX] == 3){
            ////////////////////////////////////////////////////////////////////////////////////////// 
            /// Spawning Taller Diamond Tower. 
            /// Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            /// Spawns the Cube & Diamond asset on top to create a taller tower with a diamond on top
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),0.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),1.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<DiamondAsset>(Spawn, glm::vec3((pointX),2.0f,(pointZ*pointY)), 
                                                              glm::vec3((pointX)+10.f,2.0f+10.0f,(pointZ*pointY)+10.0f), false,
                                                              Normal_Rotation, true,
                                                              Normal_Size, false));

   }
    else if( world[pointY][pointX] == 4){
            ////////////////////////////////////////////////////////////////////////////////////////// 
            /// Tree Spawn. 
            /// Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            /// Spawns the multiple voxels to create a shape of a simple tree, It uses multiple
            /// layers to get each seperate part to spawn.
            //////////////////////////////////////////////////////////////////////////////////////////
            // Tree Ground
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            // Tree Trunk
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),0.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),1.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));        
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),2.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),3.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX),4.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            // Tree Leaves - Bottom Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),3.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),3.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,3.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),3.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),3.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),3.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),3.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,3.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),3.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),3.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),3.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),3.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),3.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),3.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false)); 

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),3.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),3.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,3.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),3.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),3.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),3.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),3.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,3.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn,glm::vec3((pointX-1),3.0f,(pointZ*pointY+2)),                                                       
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),3.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            // Tree Leaves - Second Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),4.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),4.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,4.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),4.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),4.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),4.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),4.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,4.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),4.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),4.0f,(pointZ*pointY-2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),4.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),4.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),4.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),4.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),4.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),4.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,4.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),4.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),4.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+2),4.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),4.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX),4.0f,(pointZ*pointY+2)),  
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),4.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-2),4.0f,(pointZ*pointY+2)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            // Tree Leaves - Third Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),5.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,5.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),5.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false)); 

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),5.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,5.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),5.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
 
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),5.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,5.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),5.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));

            // Tree Leaves - Fourth Layer
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,6.0f,(pointZ*pointY-1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));

            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX+1),6.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,6.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX-1),6.0f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<LeavesAsset>(Spawn, glm::vec3((pointX)  ,6.0f,(pointZ*pointY+1)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
   }
    else if( world[pointY][pointX] == 5){
            //////////////////////////////////////////////////////////////////////////////////////////
            /// Spawns Pyramid Tower.  
            /// Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            /// Spawns the Cube & Pyramid asset on top to create a small tower with a diamond on top
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, glm::vec3((pointX)  ,0.00f,(pointZ*pointY)), 
                                                           glm::vec3(0.0f,0.0f,0.0f), false,
                                                           No_Rotation, false,
                                                           Normal_Size, false));
            asset_manager->AddAsset(make_shared<PyramidAsset>(Spawn, glm::vec3((pointX),0.50f,(pointZ*pointY)),
                                                              glm::vec3(0.0f,0.0f,0.0f), false,
                                                              No_Rotation, false,
                                                              Normal_Size, false));
   }
    else if( world[pointY][pointX] == 6){
            ////////////////////////////////////////////////////////////////////////////////////////// 
            /// Spawns Pyramid.
            /// Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            /// Spawns Pyramid asset on top of the ground asset
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<PyramidAsset>(Spawn, glm::vec3((pointX),-0.50f,(pointZ*pointY)),
                                                              glm::vec3(0.0f,0.0f,0.0f), false,
                                                              No_Rotation, false,
                                                              Double_Size, false));
   }
    else if( world[pointY][pointX] == 7){
            ////////////////////////////////////////////////////////////////////////////////////////// 
            /// Grass Spawn. 
            /// Spawns the Voxel GroundAsset so it creates a two tall ground world for the world
            /// Spawns somewhat randomly multiple grass assets on top/ slighlty inside the ground asset
            /// To create the view of grass.
            //////////////////////////////////////////////////////////////////////////////////////////
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GroundAsset>(Spawn, glm::vec3((pointX),-1.00f,(pointZ*pointY)),
                                                             glm::vec3(0.0f,0.0f,0.0f), false,
                                                             No_Rotation, false,
                                                             Normal_Size, false));
            asset_manager->AddAsset(make_shared<GrassAsset>(Spawn, glm::vec3((pointX-Random/(rand() % 100)),(-0.80f),(pointZ*pointY-Random/(rand()%100))), 
                                                            glm::vec3(0.0f,0.0f,0.0f), false,
                                                            No_Rotation, false,
                                                            Normal_Size, false));            
            asset_manager->AddAsset(make_shared<GrassAsset>(Spawn, glm::vec3((pointX-Random/(rand() % 100)),(-0.70f),(pointZ*pointY-Random/(rand() % 100))), 
                                                            glm::vec3(0.0f,0.0f,0.0f), false,
                                                            No_Rotation, false,
                                                            Normal_Size, false));
            asset_manager->AddAsset(make_shared<GrassAsset>(Spawn, glm::vec3((pointX-Random/(rand() % 100)),(-0.75f),(pointZ*pointY-Random/(rand() % 100))), 
                                                            glm::vec3(0.0f,0.0f,0.0f), false,
                                                            No_Rotation, false,
                                                            Normal_Size, false));
            asset_manager->AddAsset(make_shared<GrassAsset>(Spawn,
                                                            glm::vec3((pointX-Random/(rand() % 100)),(-0.60f),(pointZ*pointY-Random/(rand() % 100))), 
                                                            glm::vec3(0.0f,0.0f,0.0f), false,
                                                            No_Rotation, false,
                                                            Normal_Size, false));
            asset_manager->AddAsset(make_shared<GrassAsset>(Spawn,
                                                            glm::vec3((pointX-Random/(rand() % 100)),(-0.50f),(pointZ*pointY-Random/(rand() % 100))), 
                                                            glm::vec3(0.0f,0.0f,0.0f), false,
                                                            No_Rotation, false,
                                                            Normal_Size, false));
   }
  }
 }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Drawing the world.
/// Draws the assets to the world by calling GameAssetManager
//////////////////////////////////////////////////////////////////////////////////////////
void GameWorld::Draw() {
        asset_manager->Draw();
   
}

void GameWorld::UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y){ 
        asset_manager->UpdateCameraPosition(control, Mouse_X, Mouse_Y);
}

/*
float GameWorld::GetLeftBoundingBox() {
        Left = Camera_X_Position - 0.5;
        return Left;
}

float GameWorld::GetRightBoundingBox() {
        Right = Camera_X_Position + 0.5;
        return Right;    
}

float GameWorld::GetTopBoundingBox() {
        Top = Camera_Y_Position + 0.5;
        return Top;       
}
float GameWorld::GetBottomBoundingBox() {
        Bottom = Camera_Y_Position - 0.5;
        return Bottom;        
}
float GameWorld::GetFrontBoundingBox() {
        Front = Camera_Z_Position + 0.5;
        return Front; 
}
float GameWorld::GetBackBoundingBox() {
        Back = Camera_Z_Position - 0.5;
        return Back;        
}*/
