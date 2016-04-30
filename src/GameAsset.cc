#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 rotate, glm::vec3 scale)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, translateTo, rotate, scale);
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

