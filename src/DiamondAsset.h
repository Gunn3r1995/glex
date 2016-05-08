#ifndef DIAMONDASSET_H
#define DIAMONDASSET_H

#include <vector>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class DiamondAsset : public GameAsset {
 public:
  DiamondAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
               glm::vec3 animateTo, bool translate_bool, 
               glm::vec3 rotate, bool rotate_bool,
               glm::vec3 scale, bool scale_bool);
  ~DiamondAsset();
  void Draw(GLuint);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
};
#endif // DIAMONDASSET_H
