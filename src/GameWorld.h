#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#include <GL/gl.h>

#include "common.h"
#include "GameAssetManager.h"
#include "CubeAsset.h"
#include "DiamondAsset.h"
#include "GroundAsset.h"
#include "LeavesAsset.h"
#include "PyramidAsset.h"


/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
 public:
  /**
   * We thread the ApplicationMode through the GameWorld ss we want to read it
   * in from the user.  Threading the state through the various function calls
   * is preferable (in this case) to having some kind of global state.
   */
  GameWorld(ApplicationMode);

  /**
   * Calling Draw() will draw the entire world.
   */
  void Draw();
  // Call Camera_Control will move in specfic direction
  void Camera_Control(char key);

        GLfloat Mouse_Sensitivity =  0.05f;
        GLfloat Player_Speed = 1.0;

        GLfloat Camera_Horizontal = 0.0;
        GLfloat Camera_Vertical = 0.0;

        glm::vec3 Camera_Position = glm::vec3(1, 2, -1);
        glm::vec3 Movement_Z;
        glm::vec3 Movement_X;


 private:
  std::shared_ptr<GameAssetManager> asset_manager;


};
#endif // GAMEWORLD_H
