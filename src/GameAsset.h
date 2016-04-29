#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

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

#include "BoundingBox.h"

class GameAsset {
 public:
  GameAsset(glm::vec3 xyzPosition);
  //void Camera(float LeftBoundingBox, float RightBoundingBox, float TopBoundingBox, float BottomBoundingBox, float FrontBoundingBox, float BackBoundingBox);
  virtual void Draw(GLuint) = 0;

  std::shared_ptr<BoundingBox> Bounding_Box;
  glm::mat4 GetTranslationMatrix();

};

#endif
