#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                     glm::vec3 animateTo, bool translate_bool, 
                     glm::vec3 rotate, bool rotate_bool,
                     glm::vec3 scale, bool scale_bool) {
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, translateTo, 
                                                     animateTo, translate_bool, 
                                                     rotate, rotate_bool, 
                                                     scale, scale_bool);
        //cout << "translateTO "<< glm::to_string(translateTo) <<endl;
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

