#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 animateTo, bool translate_bool, 
                         glm::vec3 rotate, bool rotate_bool,
                         glm::vec3 scale, bool scale_bool) {

        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        translateToSave = translateTo;
        this->translate_bool = translate_bool;

        this->rotate = rotate;
        rotateTo = rotate;
        this->rotate_bool = rotate_bool;
 
        this->scale = scale;
        scaleTo = scale;
        this->scale_bool = scale_bool;       

        //cout << "SCALE  " << glm::to_string(scale) << endl;
        //cout << "Bounding Box Created at: " << glm::to_string(translateTo)<< endl;
}

glm::mat4 BoundingBox::GetModel() {

        if(translate_bool == true) {
                Translate(glm::vec3(0.1f,0.1f,0.1f));
        }        
        if(scale_bool == true) {
                Scale(scaleTo);
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

void BoundingBox::Translate(glm::vec3 translate) {
        //Temp
	if(this->translateTo.y < 10.0f) {
                this->translateTo = this->translateTo + glm::vec3(0.0f,0.1f,0.0f);
	}
	else {
                this->translateTo = translateToSave;
	}
}

void BoundingBox::Rotate(glm::vec3 rotateTo) {
        if(this->rotate.x <= 100.1f && this->rotate.y <= 100.1f && this->rotate.z <= 100.1f) {
                this->rotate = this->rotate + glm::vec3(0.1f , 0.1f, 0.1f);
        }
        else {
                this->rotate = glm::vec3(0.1f, 0.1f, 0.1f);
        }
}

void BoundingBox::Scale(glm::vec3 scaleTo) {
	if(this->scale.x < scaleTo.x && this->scale.y < scaleTo.y && this->scale.z < scaleTo.z) {
		this->scale = this->scale + glm::vec3(0.01f,0.01f,0.01f);
	}
	else {
		this->scale = glm::vec3(1.0f,1.0f,1.0f);
	}
}

glm::vec3 BoundingBox::GetTranslateTo() {
	return translateTo;
}
