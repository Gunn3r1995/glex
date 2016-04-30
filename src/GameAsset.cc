#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition);
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

void GameAsset::Translate(glm::vec3 xyzPosition) {
	Bounding_Box->Translate(xyzPosition);
}

