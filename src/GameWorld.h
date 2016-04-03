#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/gl.h>
#else
#   error "Unknown compiler"
#endif

#include "common.h"
#include "GameAssetManager.h"
#include "CubeAsset.h"
#include "DiamondAsset.h"
#include "GroundAsset.h"
#include "LeavesAsset.h"
#include "PyramidAsset.h"
#include "GrassAsset.h"


//////////////////////////////////////////////////////////////////////////////////////////
/// GameWorld allows us to separate the management of the game world from the
/// nuts and bolts of game loop initialisation.  The GameWorld currently has
/// a very simplified scene graph consisiting of a single GameAssetManager.
//////////////////////////////////////////////////////////////////////////////////////////
class GameWorld {
 public:
  //////////////////////////////////////////////////////////////////////////////////////////
  /// We thread the ApplicationMode through the GameWorld ss we want to read it
  /// in from the user.  Threading the state through the various function calls
  /// is preferable (in this case) to having some kind of global state.
  //////////////////////////////////////////////////////////////////////////////////////////
  GameWorld(ApplicationMode);
    
          double MinimumNumber = 0.50;
          double MaximumNumber = 1.00;
          double Random = (double)rand() / RAND_MAX;      
  //////////////////////////////////////////////////////////////////////////////////////////
  /// Calling Draw(). will draw the entire world.
  //////////////////////////////////////////////////////////////////////////////////////////
  void Draw();
  //////////////////////////////////////////////////////////////////////////////////////////
  /// Call Camera_Control. will move in specfic direction
  //////////////////////////////////////////////////////////////////////////////////////////
  void Camera_Control(char key);
          //////////////////////////////////////////////////////////////////////////////////////////
          /// Camera Variables.
          /// Camera Variables Controls Speed of Play/Camera
          /// Controls the distance each movement moves by
          /// Sets where the starting positions of the camera 
          /// and the direction it is looking at
          ////////////////////////////////////////////////////////////////////////////////////////// 
          GLfloat Mouse_Sensitivity =  0.05f;
          GLfloat Player_Speed = 1.0;

          GLfloat Camera_Horizontal = 0.0;
          GLfloat Camera_Vertical = 0.0;

          glm::vec3 Camera_Position = glm::vec3(0, 2, 0);
          glm::vec3 Movement_Z;
          glm::vec3 Movement_X;

 private:
  std::shared_ptr<GameAssetManager> asset_manager;


};
#endif // GAMEWORLD_H
