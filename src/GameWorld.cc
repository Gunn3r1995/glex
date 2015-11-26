#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
  int x,y;
  int worldX = 10;
  int worldY = 10;
  int world[worldX][worldY] = {
  {1,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,1}
  };

  asset_manager = std::make_shared<GameAssetManager>(mode);
  for( x=0; x<worldX; x++){ 
   for (y=0; y<worldY; y++){
    if( world[worldY][worldX] == 1){
    asset_manager->AddAsset(std::make_shared<CubeAsset>(x,y));
  }
 }
}

  
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
