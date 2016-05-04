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

  /*

        asset_manager->AddAsset(make_shared<CubeAsset>(glm::vec3(0.0f ,0.00f, 0.0f), 2, 1, glm::vec3(0.2f, 0.2f, 0.2f)));
        asset_manager->AddAsset(make_shared<CubeAsset>(glm::vec3(0.0f ,2.00f, 0.0f), 0, 1,  glm::vec3(0.0f, 0.0f, 0.0f)));
        //asset_manager->AddAsset(make_shared<GroundAsset>(glm::vec3(2.0f ,4.00f, 0.0f), 2, 1, glm::vec3(0.2f,0.2f,0.2)));

        asset_manager->AddAsset(make_shared<CubeAsset>(glm::vec3(0.0f ,1.00f, 0.0f), 2, 1, glm::vec3(0.2f, 0.2f, 0.2f)));*/
        
  //////////////////////////////////////////////////////////////////////////////////////////
  /// Spawning different Voxels.
  /// Spawns all the Voxel assets I made just outside the array space,
  /// Just so you can view each voxel on it's own
  //////////////////////////////////////////////////////////////////////////////////////////

       // asset_manager->AddAsset(make_shared<GroundAsset>( glm::vec3(1.0f ,2.00f, -4.0f), 0, glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
        //asset_manager->AddAsset(make_shared<CubeAsset>(   glm::vec3(3.0f ,2.00f, -4.0f), 3, glm::vec3(2.0f,2.0f,2.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
        //asset_manager->AddAsset(make_shared<LeavesAsset>( glm::vec3(5.0f ,2.00f, -4.0f), 0, glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
        //asset_manager->AddAsset(make_shared<DiamondAsset>(glm::vec3(0.0f ,0.00f, 0.0f), 2, glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
        //asset_manager->AddAsset(make_shared<PyramidAsset>(glm::vec3(7.0f ,1.50f, -4.0f), 3, glm::vec3(2.0f,2.0f,2.0f), glm::vec3(0.0f, 0.0f, 0.0f))); 
        //asset_manager->AddAsset(make_shared<GrassAsset>(  glm::vec3(9.0f,1.50f, -4.0f), 0, glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));

   /////////////////////////////////////////////////////////////////////////////////////////
   //AddAsset Layout 
   //This adds the asset to the game asset manager which draws it to the screen
   //
   //  asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, Translate
   //                                                 AnimateTo , Bool,
   //                                                 Rotation, Bool,
   //                                                 Scale, Bool));  
   /////////////////////////////////////////////////////////////////////////////////////////
        //Spawn_Cube = asset_manager->AddAsset(make_shared<CubeAsset>);
        /*
        asset_manager->AddAsset(make_shared<DiamondAsset>(Spawn, 
                                                       glm::vec3(1.0f ,2.00f, -4.0f), false,
                                                       Normal_Rotation, true,
                                                       Double_Size, false));

        //asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, 
        //                                               glm::vec3(1.0f ,2.00f, -4.0f), false,
        //                                               Normal_Rotation, true,
        //                                               Double_Size, false));

        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn,
                                                       glm::vec3(2.0f ,2.00f, -4.0f), false,
                                                       No_Rotation, false,
                                                       Normal_Size, false));

        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, 
                                                       glm::vec3(4.0f ,2.00f, -4.0f), false,
                                                       No_Rotation, false,
                                                       Double_Size, true));

        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn,
                                                       glm::vec3(6.0f ,2.00f, -4.0f), true,
                                                       No_Rotation, false,
                                                       Normal_Size, false));

        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn, 
                                                       glm::vec3(7.0f ,2.00f, -4.0f), false,
                                                       Normal_Rotation, true,
                                                       Normal_Size, false));
        

        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn,
                                                       glm::vec3(4.0f ,2.00f, -4.0f), true,
                                                       No_Rotation, false,
                                                       Normal_Size, false));
        
        asset_manager->AddAsset(make_shared<CubeAsset>(Spawn,
                                                       glm::vec3(6.0f ,2.00f, -4.0f), false,
                                                       No_Rotation, false,
                                                       Normal_Size, false));

        */

       // asset_manager->AddAsset(make_shared<DiamondAsset>(glm::vec3(0.0f ,0.00f, 0.0f), 2, glm::vec3(1.0f,1.0f,1.0f), glm::vec3(0.2f, 0.2f, 0.2f)));

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
  /// Controls calculations
  /// Controls all the movement and positions of the camera 
  /// Uses keyboard and Mouse movements to move around the world space
  /// Tells the Camera matrix what position to look at and where to move
  //////////////////////////////////////////////////////////////////////////////////////////
void GameWorld::Camera_Control(char key) {

        Old_Camera_Position = Camera_Position;
	Old_Camera_X_Position = Camera_X_Position;
	Old_Camera_Y_Position = Camera_Y_Position;
	Old_Camera_Z_Position = Camera_Z_Position;

  if ( key == 'w' ) {        // W Key Pressed will move Camera forward
        Camera_Position +=  Movement_Z * Player_Speed;
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
  if (key == '^') {          // Camera look Up
        Camera_Vertical += 0.5f * Mouse_Sensitivity;
 }
  if (key == '<') {          // Camera look left
        Camera_Horizontal += 0.5f * Mouse_Sensitivity;
 }
  if (key == 'v') {          // Camera look down
        Camera_Vertical -= 0.5f * Mouse_Sensitivity;
 }
  if (key == '>') {          // Camera look right
        Camera_Horizontal -= 0.5f * Mouse_Sensitivity;
 }
  if (key == '+') {          // Jump up/ 0.1, Would like to improve it to a actually jump mechanic
        Camera_Position += 0.1f * Player_Speed;
 }
  if (key == '-') {          // Drop down/ -0.1
        Camera_Position -= 0.1f * Player_Speed;
 }
  if (key == 'i') {
        cout << "Bounding Box Left: "<< GetLeftBoundingBox() << endl;
        cout << "Bounding Box Right: "<< GetRightBoundingBox() << endl;
        cout << "Bounding Box Top: "<< GetTopBoundingBox() << endl;
        cout << "Bounding Box Bottom: "<< GetBottomBoundingBox() << endl;
        cout << "Bounding Box Front: "<< GetFrontBoundingBox() << endl;
        cout << "Bounding Box Back: "<< GetBackBoundingBox() << endl;
               
}
        //Game_Asset->Camera(GetLeftBoundingBox(), GetRightBoundingBox(), GetTopBoundingBox(), GetBottomBoundingBox(), GetFrontBoundingBox(), GetBackBoundingBox());

        //cout << "Current Pos = " << glm::to_string(Camera_Position) << endl;
        //cout << "Old Pos = " << glm::to_string(Old_Camera_Position) << endl;
        //cout << Camera_Vertical << endl;
        
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Drawing the world.
/// Draws the assets to the world by calling GameAssetManager
/// Sends the camera positions and movements to the translate shader
//////////////////////////////////////////////////////////////////////////////////////////
void GameWorld::Draw() {
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

        
        Camera_X_Position = -Camera_Position[0];
	Camera_Y_Position = Camera_Position[1];
	Camera_Z_Position = Camera_Position[2];

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Restrict the View
        /// These If statements stop the Camera Vertical going above 2.0 or below -2.0
        //////////////////////////////////////////////////////////////////////////////////////////
        if(Camera_Vertical >= 2.0f){
                Camera_Vertical = 1.975f;     
        }
        else if(Camera_Vertical <= -2.0f){
                Camera_Vertical = -1.975f;
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

        //////////////////////////////////////////////////////////////////////////////////////////
        /// Send data to Uniform Variable.
        /// Sends the data to the translate.vs shader
        //////////////////////////////////////////////////////////////////////////////////////////
	glUniformMatrix4fv(0, 1, GL_FALSE, &Camera_Projection[0][0]);
	glUniformMatrix4fv(1, 1, GL_FALSE, &Camera_View[0][0]);
	glUniformMatrix4fv(2, 1, GL_FALSE, &Camera_Model[0][0]);

        asset_manager->Draw(Camera_Projection, Camera_View);
   
}

float GameWorld::GetLeftBoundingBox(){
        Left = Camera_X_Position - 0.5;
        return Left;
}

float GameWorld::GetRightBoundingBox(){
        Right = Camera_X_Position + 0.5;
        return Right;    
}

float GameWorld::GetTopBoundingBox(){
        Top = Camera_Y_Position + 0.5;
        return Top;       
}
float GameWorld::GetBottomBoundingBox(){
        Bottom = Camera_Y_Position - 0.5;
        return Bottom;        
}
float GameWorld::GetFrontBoundingBox(){
        Front = Camera_Z_Position + 0.5;
        return Front; 
}
float GameWorld::GetBackBoundingBox(){
        Back = Camera_Z_Position - 0.5;
        return Back;        
}
