#include "GameAsset.h"

GameAsset::GameAsset(float x, float y, float z)
{
	Bounding_Box = std::make_shared<BoundingBox>(x, y, z);
}

glm::mat4 GameAsset::GetTranslationMatrix()
{
	return Bounding_Box->GetTranslationMatrix();
}
