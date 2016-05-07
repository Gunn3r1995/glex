#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/gl.h>
#else
#   error "Unknown compiler"
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
                int GetDrawList();
                void AddAsset(std::shared_ptr<GameAsset>);
                void Draw();
                void UpdateCameraPosition(Control control, int Mouse_X, int Mouse_Y);

         private:
                GLuint CreateGLProgram(std::string &, std::string &);
                GLuint CreateGLESShader(GLenum, std::string &);
                // As this is private and we're writing to the GPU, we will use raw pointers.
                std::pair<GLchar *, GLint>  ReadShader(std::string &);

                glm::mat4 Camera_View;
                glm::mat4 Camera_Projection;

	        // variables to gather the bounds of two bounding boxes to check collisions
                glm::vec3 bounding_box1_max;
                glm::vec3 bounding_box1_min;
                glm::vec3 bounding_box2_max;
                glm::vec3 bounding_box2_min;
                
                glm::vec3 BB1_Pos;
                glm::vec3 BB2_Pos;

                // The internal scene graph is a simple list.
                std::vector<std::shared_ptr<GameAsset>> draw_list;
                Camera camera;
                GLuint program_token;
};
#endif // GAMEASSETMANAGER_H
