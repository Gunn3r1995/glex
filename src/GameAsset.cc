#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 rotate)
{
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, translateTo, rotate);
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

//void GameAsset::Translate(glm::vec3 translateTo) {
//	Bounding_Box->Translate(translateTo);
//}

