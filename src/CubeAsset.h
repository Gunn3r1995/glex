#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

using namespace std;

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#elif __linux__
#include <GL/gl.h>
#else
#   error "Unknown compiler"
#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"
#include "GameAssetManager.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset(GLfloat x, GLfloat y, GLfloat z);
  ~CubeAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
  void checkError(std::string file, int line);
  std::shared_ptr<GameAssetManager> asset_manager;


  float XBoundingBox;
  float YBoundingBox;
  float ZBoundingBox;

  float LeftBoundingBox;
  float RightBoundingBox;
  float TopBoundingBox;
  float BottomBoundingBox;
  float FrontBoundingBox;
  float BackBoundingBox;
};

#endif // CUBEASSET_H
