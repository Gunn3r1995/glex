#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, translateTo);
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

void GameAsset::Translate(glm::vec3 translateTo) {
	Bounding_Box->Translate(translateTo);
}

