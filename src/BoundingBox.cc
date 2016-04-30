#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition) {
	
        this->xyzPosition = xyzPosition;
        cout<<"Bounding Box Created at: X:"<<xyzPosition.x<<" Y: "<<xyzPosition.y<<" Z: "<<xyzPosition.z<<endl;
}

glm::mat4 BoundingBox::GetModel() {

        glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->xyzPosition));
        model_matrix = translate_matrix;
        return model_matrix;
}

void BoundingBox::Translate(glm::vec3 translate) {

	this->xyzPosition = translateXYZ - xyzPosition;
}

glm::vec3 BoundingBox::GetxyzPosition() {

	return xyzPosition;
}
