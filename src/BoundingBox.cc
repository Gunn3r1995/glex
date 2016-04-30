#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, bool translate_bool, 
                         glm::vec3 rotate, bool rotate_bool,
                         glm::vec3 scale, bool scale_bool) {

        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        this->translate_bool = translate_bool;

        this->rotate = rotate;
        this->rotate_bool = rotate_bool;
 
        this->scale = scale;
        this->scale_bool = scale_bool;        

        cout<<"SCALE X: "<<scale.x<<" Y: "<<scale.y<<" Z: "<<scale.z<<endl;
        cout<<"Bounding Box Created at: X:"<<xyzPosition.x<<" Y: "<<xyzPosition.y<<" Z: "<<xyzPosition.z<<endl; 
}

glm::mat4 BoundingBox::GetModel() {
        
        if(scale_bool == true) {
                Scale(glm::vec3(0.1f,0.1f,0.1f));
        }
        if(rotate_bool == true) {
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

	if(this->translateTo.x < 2.0f, this->translateTo.y < 2.0f, this->translateTo.z < 2.0f) {
                this->translateTo = this->translateTo + translateTo;
	}
	else {
                trajectory = translateTo;
	}
}

void BoundingBox::Rotate(glm::vec3 rotate) {
        
        if(this->rotate.x <= 100.1f && this->rotate.y <= 100.1f && this->rotate.z <= 100.1f) {
                this->rotate = this->rotate + glm::vec3(0.1f , 0.1f, 0.1f);
        }
        else {
                this->rotate = glm::vec3(0.1f, 0.1f, 0.1f);
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
