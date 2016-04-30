#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 rotate, glm::vec3 scale) {

        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        this->rotate = rotate;
        this->scale = scale;
        
        cout<<"SCALE X: "<<scale.x<<" Y: "<<scale.y<<" Z: "<<scale.z<<endl;
        cout<<"Bounding Box Created at: X:"<<xyzPosition.x<<" Y: "<<xyzPosition.y<<" Z: "<<xyzPosition.z<<endl; 
}

glm::mat4 BoundingBox::GetModel() {
        
        if(this->scale.x > 1.0f && this->scale.y > 1.0f && this->scale.z > 1.0f) {
                Scale(glm::vec3(0.1f,0.1f,0.1f));
        }
        else if(this->rotate.x > 0.0f && this->rotate.y > 0.0f && this->rotate.z > 0.0f) {
                Rotate(glm::vec3(0.1f, 0.1f, 0.1f));
        }

        Translate_Matrix = glm::translate(glm::mat4(), glm::vec3(this->translateTo));
        Scale_Matrix = glm::scale(glm::vec3(this->scale));

        Model_Matrix = Translate_Matrix * Scale_Matrix;

        Model_Matrix = glm::rotate(Model_Matrix, this->rotate.x, glm::vec3(1, 0, 0));
        Model_Matrix = glm::rotate(Model_Matrix, this->rotate.y, glm::vec3(0, 1, 0));
        Model_Matrix = glm::rotate(Model_Matrix, this->rotate.z, glm::vec3(0, 0, 1));
        
        return Model_Matrix;
}

void BoundingBox::Translate(glm::vec3 translateTo) {

        //Implement This Later
}

void BoundingBox::Rotate(glm::vec3 rotate) {
        
        if(this->rotate.x <= 5.0f && this->rotate.y <= 5.0f && this->rotate.z <= 5.0f) {
                this->rotate += this->rotate + glm::vec3(0.01f , 0.1f, 0.1f);
        }
        else {
                this->rotate = glm::vec3(0.01f, 0.1f, 0.1f);
        }
}

void BoundingBox::Scale(glm::vec3 scale) {

	float Increased_Scale;
	if(this->scale.x < 5.0f) {
		this->scale = this->scale + scale;
	}
	else {
		this->scale = glm::vec3(1.1f,1.1f,1.1f);
	}
}

glm::vec3 BoundingBox::GetxyzPosition() {

	return xyzPosition;
}
