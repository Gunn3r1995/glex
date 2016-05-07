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

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset : public GameAsset {
 public:
  CubeAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
            glm::vec3 animateTo, bool translate_bool, 
            glm::vec3 rotate, bool rotate_bool,
            glm::vec3 scale, bool scale_bool);
  ~CubeAsset();
  virtual void Draw(GLuint);
  glm::vec3 GetVec3();

 private:
  glm::vec3 Position;
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;

};

#endif // CUBEASSET_H
