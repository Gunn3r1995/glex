#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition);
}

glm::mat4 GameAsset::GetTranslationMatrix()
{
	return Bounding_Box->GetTranslationMatrix();
}

