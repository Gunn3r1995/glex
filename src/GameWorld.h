#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include "glm/gtx/string_cast.hpp"

using namespace std;


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
#include "GameAsset.h"
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

                GLfloat Camera_X_Position = 0;
                GLfloat Camera_Y_Position = 2;
                GLfloat Camera_Z_Position = 0;

                GLfloat Old_Camera_X_Position;
                GLfloat Old_Camera_Y_Position;
                GLfloat Old_Camera_Z_Position;

                glm::vec3 Camera_Position = glm::vec3(Camera_X_Position, Camera_Y_Position, Camera_Z_Position);
                glm::vec3 Old_Camera_Position = Camera_Position;

                glm::vec3 Movement_Z;

                glm::vec3 Movement_X;

                float GetBoundingBox();
                float GetLeftBoundingBox();
                float GetRightBoundingBox();
                float GetTopBoundingBox();
                float GetBottomBoundingBox();
                float GetFrontBoundingBox();
                float GetBackBoundingBox();
                
        private:
                float Left;
                float Right;
                float Top;
                float Bottom;
                float Front;
                float Back;

                //////////////////////////////////////////////////////////////////////////////////////////
                /// Spawn Variables.
                /// These are some default vectors to reduce the size and make it easier
                /// to read the spawning of each asset
                //////////////////////////////////////////////////////////////////////////////////////////               
                glm::vec3 Spawn = glm::vec3(0.0f,0.0f,0.0f);

                glm::vec3 No_Rotation = glm::vec3(0.0f,0.0f,0.0f);
                glm::vec3 Normal_Rotation = glm::vec3(0.2f,0.2f,0.2f);
                glm::vec3 Fast_Rotation = glm::vec3(1.0f,1.0f,1.0f);

                glm::vec3 Normal_Size = glm::vec3(1.0f,1.0f,1.0f);
                glm::vec3 Double_Size = glm::vec3(2.0f,2.0f,2.0f); 
                glm::vec3 Giant_Size = glm::vec3(10.0f,10.0f,10.0f);

                std::shared_ptr<GameAssetManager> asset_manager;
                std::shared_ptr<GameAsset> Game_Asset;
                //std::shared_ptr<BoundingBox> Bounding_Box;
};
#endif // GAMEWORLD_H
