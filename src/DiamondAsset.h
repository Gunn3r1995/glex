#ifndef DIAMONDASSET_H
#define DIAMONDASSET_H
using namespace std;
#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class DiamondAsset : public GameAsset {
 public:
  DiamondAsset(GLfloat x, GLfloat y, GLfloat z);
  ~DiamondAsset();
  virtual void Draw(GLuint);

 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
  void checkError(string file, int line);
};

#endif // DIAMONDASSET_H
