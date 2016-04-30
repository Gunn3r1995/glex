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

#include "common.h"
#include "GameAsset.h"
#include "CubeAsset.h"

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
        void CollisionDetection();
        void Draw(glm::mat4, glm::mat4);

 private:
        GLuint CreateGLProgram(std::string &, std::string &);
        GLuint CreateGLESShader(GLenum, std::string &);
        // As this is private and we're writing to the GPU, we will use raw pointers.
        std::pair<GLchar *, GLint>  ReadShader(std::string &);

        // The internal scene graph is a simple list.
        std::vector<std::shared_ptr<GameAsset>> draw_list;
        std::vector<std::shared_ptr<CubeAsset>> asset_list;
        GLuint program_token;
};
#endif // GAMEASSETMANAGER_H
