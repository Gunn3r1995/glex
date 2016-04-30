#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 rotate) {

        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        this->rotate = rotate;
        cout<<"Bounding Box Created at: X:"<<xyzPosition.x<<" Y: "<<xyzPosition.y<<" Z: "<<xyzPosition.z<<endl; 
}

glm::mat4 BoundingBox::GetModel() {

        this->Rotate(this->rotate);

        glm::mat4 translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->translateTo));
        model_matrix = translate_matrix;

        model_matrix = glm::rotate(model_matrix, this->rotate.x, glm::vec3(1, 0, 0));
        model_matrix = glm::rotate(model_matrix, this->rotate.y, glm::vec3(0, 1, 0));
        model_matrix = glm::rotate(model_matrix, this->rotate.z, glm::vec3(0, 0, 1));
        
        return model_matrix;
}

void BoundingBox::Translate(glm::vec3 translateTo) {

        //Implement This Later
}

void BoundingBox::Rotate(glm::vec3 rotate) {

        glm::vec3 new_rotate;
        new_rotate = this->rotate + rotate;
	this->rotate = new_rotate;
}

glm::vec3 BoundingBox::GetxyzPosition() {

	return xyzPosition;
}
