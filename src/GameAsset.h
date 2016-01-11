#ifndef GAMEASSET_H
#define GAMEASSET_H

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

class GameAsset {
 public:
  virtual void Draw(GLuint) = 0;

};

#endif
