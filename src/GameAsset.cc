#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, bool translate_bool, 
                     glm::vec3 rotate, bool rotate_bool,
                     glm::vec3 scale, bool scale_bool) {
	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, 
                                                     translateTo, translate_bool, 
                                                     rotate, rotate_bool, 
                                                     scale, scale_bool);
        //cout << "translateTO X: "<< translateTo.x<< " Y: "<<translateTo.y<<" Z: "<<translateTo.z<<endl;
        this->translateTo = translateTo;

        BoundingBoxCollision(translateTo);
}

void GameAsset::BoundingBoxCollision(glm::vec3 translate_To) {
        glm::vec3 Array[100];
        glm::vec3 x = translate_To;
        Array[0] = x;
        cout << Array[0].x << endl;
}

glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

