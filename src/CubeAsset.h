#ifndef CUBEASSET_H
#define CUBEASSET_H

#include <vector>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

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
  void Draw(GLuint);
  glm::vec3 GetVec3();

 private:
  glm::vec3 Position;
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;

};

#endif // CUBEASSET_H
