#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 rotate)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, rotate);
}

glm::mat4 GameAsset::GetTranslationMatrix()
{
	return Bounding_Box->GetTranslationMatrix();
}

