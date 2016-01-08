#ifndef LEAVESASSET_H
#define LEAVESASSET_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

using namespace std;

class LeavesAsset : public GameAsset {
 public:
  LeavesAsset(GLfloat x, GLfloat y, GLfloat z);
  ~LeavesAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length, colour_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token, colour_buffer_token;
  void checkError(string file, int line);
};

#endif // LEAVESASSET_H