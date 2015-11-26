#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
  int pointX,pointY;
  int worldX = 15;
  int worldY = 15;
  int world[worldY][worldX] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };

  asset_manager = std::make_shared<GameAssetManager>(mode);

  for( pointX=0; pointX<worldX; pointX++){
   for (pointY=0; pointY<worldY; pointY++){
    if( world[pointY][pointX] == 1){
    asset_manager->AddAsset(std::make_shared<CubeAsset>((pointX-8),-(pointY-7)));
   }
  }
 } 
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
