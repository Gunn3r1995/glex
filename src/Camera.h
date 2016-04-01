#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/ext.hpp>
#include <vector>
#include <memory>
#include "common.h"
#include "GameAsset.h"

class Camera{

public:
  Camera();
  glm::mat4 CameraUpdate(Movement movement, int Mouse_X, int Mouse_Y);
private:

};

#endif // CAMERA_H_
