#ifndef GRASSASSET_H
#define GRASSASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class GrassAsset : public GameAsset {
 public:
  GrassAsset(GLfloat x, GLfloat y, GLfloat z);
  ~GrassAsset();
  virtual void Draw(GLuint);
  void checkError(std::string file, int line);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
};

#endif /// GRASSASSET_H
