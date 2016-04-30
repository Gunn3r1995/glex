#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo) {
	
        cout<<"translate Created at: X:"<<translateTo.x<<" Y: "<<translateTo.y<<" Z: "<<translateTo.z<<endl;
        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        cout<<"Bounding Box Created at: X:"<<xyzPosition.x<<" Y: "<<xyzPosition.y<<" Z: "<<xyzPosition.z<<endl; 
        cout<<"translate Created at: X:"<<translateTo.x<<" Y: "<<translateTo.y<<" Z: "<<translateTo.z<<endl;
}

glm::mat4 BoundingBox::GetModel() {

        glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->translateTo));
        model_matrix = translate_matrix;
        return model_matrix;
}

void BoundingBox::Translate(glm::vec3 translateTo) {

	//this->xyzPosition = translateXYZ - xyzPosition;
}

glm::vec3 BoundingBox::GetxyzPosition() {

	return xyzPosition;
}
