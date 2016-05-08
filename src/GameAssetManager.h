#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <string>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "glm/gtx/string_cast.hpp"


#include "common.h"
#include "GameAsset.h"
#include "Camera.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
/// GameAssetManager is a container for GameAssets.  It also provides utility
/// functions to to create a simple OpenGL program that can be used to draw a
/// simple GameAsset.
//////////////////////////////////////////////////////////////////////////////////////////
class GameAssetManager {
         public:
                explicit GameAssetManager(ApplicationMode); // constructor
                virtual ~GameAssetManager();
                GameAssetManager(GameAssetManager const&); // copy constructor
                GameAssetManager(GameAssetManager const&&); // move constructor
                void operator = (GameAssetManager); // assignment
                void AddAsset(std::shared_ptr<GameAsset>);
                void Draw();
                void UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y);

         private:
                GLuint CreateGLProgram(std::string &, std::string &);
                GLuint CreateGLESShader(GLenum, std::string &);
                // As this is private and we're writing to the GPU, we will use raw pointers.
                std::pair<GLchar *, GLint>  ReadShader(std::string &);

                glm::mat4 Camera_View, Camera_Projection;
             
                glm::vec3 BB1_Max, BB1_Min, BB1_Pos, BB2_Max, BB2_Min, BB2_Pos;

                // The internal scene graph is a simple list.
                std::vector<std::shared_ptr<GameAsset>> draw_list;
                Camera camera;
                GLuint program_token;
};
#endif // GAMEASSETMANAGER_H
