#ifndef PYRAMIDASSET_H
#define PYRAMIDASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

using namespace std;

class PyramidAsset : public GameAsset {
 public:
  PyramidAsset(GLfloat x, GLfloat y, GLfloat z);
  ~PyramidAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
  void checkError(string file, int line);
};

#endif // PYRAMIDASSET_H