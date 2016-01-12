#ifndef LEAVESASSET_H
#define LEAVESASSET_H

#include <vector>

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

class LeavesAsset : public GameAsset {
 public:
  LeavesAsset(GLfloat x, GLfloat y, GLfloat z);
  ~LeavesAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
  void checkError(std::string file, int line);
};

#endif // LEAVESASSET_H
