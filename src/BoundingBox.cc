#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 animateTo, bool translate_bool, 
                         glm::vec3 rotate, bool rotate_bool,
                         glm::vec3 scale, bool scale_bool) {
        //////////////////////////////////////////////////////////////////////////////////////////
        ///Initalise Data 
        ///The below vectors and booleans initialise all the variables used in the bounding box
        ///class to calculate and animate the Bounding Box
        ////////////////////////////////////////////////////////////////////////////////////////// 
        this->xyzPosition = xyzPosition;
        this->translateTo = translateTo;
        translateToSave = translateTo;
        this->animateTo = animateTo;
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

//////////////////////////////////////////////////////////////////////////////////////////
/// Get Model
/// This Controls and calls whether it should be Animated by calling the 
/// Translate, Scale and Rotate Methods. 
/// It also caluclates the Translate, Scale and Model Matrix to return the Model Matrix
/// to eventually the GameAssetManager Class
//////////////////////////////////////////////////////////////////////////////////////////
glm::mat4 BoundingBox::GetModel() {
        
        if(translate_bool == true) {
                TranslateX();
                TranslateY();
                TranslateZ();
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

//////////////////////////////////////////////////////////////////////////////////////////
///Translate Method
///This controls the translation animation, to move the assets on the x, y or z axis
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::TranslateX() {
        if( this->translateTo.y < animateTo.y || this->translateTo.y != animateTo.y){
	        if(this->translateTo.x < animateTo.x ) {
                       this->translateTo = this->translateTo + glm::vec3(0.1f,0.0f,0.0f);
                }
                else if(this->translateTo.x > animateTo.x){
                  this->translateTo = this->translateTo + glm::vec3(-0.1f,0.0f,0.0f);
                }
        }
        else if(translateTo.y == animateTo.y ){
	        if(this->translateTo.x < animateTo.x ) {
                       this->translateTo = this->translateTo + glm::vec3(0.1f,0.0f,0.0f);
                }
                else if(this->translateTo.x > animateTo.x){
                  this->translateTo = this->translateTo + glm::vec3(-0.1f,0.0f,0.0f);
                }
        }
	else {
                this->translateTo = translateToSave;
	}
}

void BoundingBox::TranslateY() {
        if( this->translateTo.y < animateTo.y || this->translateTo.y != animateTo.y){
	        if(this->translateTo.y < animateTo.y ) {
                       this->translateTo = this->translateTo + glm::vec3(0.0f,0.1f,0.0f);
                }
                else if(this->translateTo.y > animateTo.y){
                  this->translateTo = this->translateTo + glm::vec3(0.0f,-0.1f,0.0f);
                }
                else {
                        this->translateTo = translateToSave;
	        }
        }
        else if(translateTo.y == animateTo.y ){
                TranslateX();
        }
	else {
                this->translateTo = translateToSave;
	}
}
void BoundingBox::TranslateZ() {
        if( this->translateTo.y < animateTo.y || this->translateTo.y != animateTo.y){
	        if(this->translateTo.z < animateTo.z ) {
                       this->translateTo = this->translateTo + glm::vec3(0.0f,0.0f,0.1f);
                }
                else if(this->translateTo.z > animateTo.z){
                  this->translateTo = this->translateTo + glm::vec3(0.0f,0.0f,-0.1f);
                }
        }
        else if(this->translateTo.y == animateTo.y){
                if(this->translateTo.z < animateTo.z ) {
                       this->translateTo = this->translateTo + glm::vec3(0.0f,0.0f,0.1f);
                }
                else if(this->translateTo.z > animateTo.z){
                  this->translateTo = this->translateTo + glm::vec3(0.0f,0.0f,-0.1f);
                }
        }
	else {
                this->translateTo = translateToSave;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Rotate Method
/// Controls the rotation of the asset
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::Rotate(glm::vec3 rotateTo) {
        if(this->rotate.x <= 100.1f && this->rotate.y <= 100.1f && this->rotate.z <= 100.1f) {
                this->rotate = this->rotate + glm::vec3(0.1f , 0.1f, 0.1f);
        }
        else {
                this->rotate = glm::vec3(0.1f, 0.1f, 0.1f);
        }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Scale Method
/// Controls the size of the Asset
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::Scale(glm::vec3 scaleTo) {
	if(this->scale.x < scaleTo.x && this->scale.y < scaleTo.y && this->scale.z < scaleTo.z) {
		this->scale = this->scale + glm::vec3(0.01f,0.01f,0.01f);
	}
	else {
		this->scale = glm::vec3(1.0f,1.0f,1.0f);
	}
}    

/**
 * Return the max and minimum bounds
 */
glm::vec3 BoundingBox::GetAABB(string check)
{
    if (check == "Max")
    {
        AABB = this->translateTo += glm::vec3(1.0f,1.0f,1.0f) * this->scale;
    }
    else if (check == "Min")
    {
        AABB = this->translateTo += glm::vec3(-1.0f,-1.0f,-1.0f) * this->scale;
    }
    return AABB;
}

void BoundingBox::CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos,
                                     glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos)
{
    if (BB1_Max.x > BB2_Min.x && BB1_Min.x < BB2_Max.x &&
        BB1_Max.y > BB2_Min.y && BB1_Min.y < BB2_Max.y &&
        BB1_Max.z > BB2_Min.z && BB1_Min.z < BB2_Max.z)
    {
        cout << "Collision" << endl;
        cout << "BB1 Pos: " << glm::to_string(BB1_Pos) << endl;
        cout << "BB1 Max: " << glm::to_string(BB1_Max) << endl;
        cout << "BB1 Min: " << glm::to_string(BB1_Min) << endl;
        cout << "----------------------------------------------" << endl;
        cout << "BB2 Pos: " << glm::to_string(BB2_Pos) << endl;
        cout << "BB2 Max: " << glm::to_string(BB2_Max) << endl;
        cout << "BB2 Min: " << glm::to_string(BB2_Min) << endl;
        cout << "*****************************************************" << endl;
        translateTo = translateToSave;
        this->scale = scaleTo;
        this->rotate = rotateTo;
    }
}  

//////////////////////////////////////////////////////////////////////////////////////////
/// GetTranslateTo
/// Returns the Current position the BoundingBox is at
//////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 BoundingBox::GetTranslateTo() {
	return this->translateTo;
}

bool BoundingBox::GetTranslateBool() {
	return this->translate_bool;
}

bool BoundingBox::GetScaleBool() {
	return this->scale_bool;
}

bool BoundingBox::GetRotateBool() {
	return this->rotate_bool;
}

