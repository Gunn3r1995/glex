#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 animateTo, bool translate_bool, 
                         glm::vec3 rotate, bool rotate_bool,
                         glm::vec3 scale, bool scale_bool, string &AssetType) {
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
        this->AssetType = AssetType;

        cout << "Bounding Box Created at: " << glm::to_string(translateTo)<< endl;
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

        Translate_Matrix = glm::translate(glm::mat4(), glm::vec3(translateTo));
        Scale_Matrix = glm::scale(glm::vec3(scale));

        Model_Matrix = Translate_Matrix * Scale_Matrix;

        Model_Matrix = glm::rotate(Model_Matrix, rotate.x, glm::vec3(1, 0, 0));
        Model_Matrix = glm::rotate(Model_Matrix, rotate.y, glm::vec3(0, 1, 0));
        Model_Matrix = glm::rotate(Model_Matrix, rotate.z, glm::vec3(0, 0, 1));
        
        return Model_Matrix;
}

//////////////////////////////////////////////////////////////////////////////////////////
///Translate Method
///This controls the translation animation, to move the assets on the x, y or z axis
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::TranslateX() {
                if(translateTo.x < animateTo.x ) {
                        translateTo = translateTo + glm::vec3(0.1f,0.0f,0.0f);
                        
                        if(translateTo.x > animateTo.x){
                                translateTo = translateToSave;
                        }
                }
                else if(translateTo.x > animateTo.x) {
                        translateTo = translateTo + glm::vec3(-0.1f,0.0f,0.0f);

                        if(translateTo.x < animateTo.x){
                                translateTo = translateToSave;
                        }
                }
}

void BoundingBox::TranslateY() {
	        if(translateTo.y < animateTo.y ) {
                       translateTo = translateTo + glm::vec3(0.0f,0.1f,0.0f);
                       
                       if(translateTo.y > animateTo.y){
                                translateTo = translateToSave;
                       }
                }
                else if(translateTo.y > animateTo.y){
                        translateTo = translateTo + glm::vec3(0.0f,-0.1f,0.0f);
                  
                        if(translateTo.y < animateTo.y){
                                translateTo = translateToSave;
                        }
                }
}
void BoundingBox::TranslateZ() {
                if(translateTo.z < animateTo.z ) {
                        translateTo = translateTo + glm::vec3(0.0f,0.0f,0.1f);
                        
                        if(translateTo.z > animateTo.z){
                                translateTo = translateToSave;
                        }
                }
                else if(translateTo.z > animateTo.z){
                        translateTo = translateTo + glm::vec3(0.0f,0.0f,-0.1f);
                        
                        if(translateTo.z < animateTo.z){
                                translateTo = translateToSave;
                        }
                }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Rotate Method
/// Controls the rotation of the asset
////////////////////////////////////////////////////////////////////////////////////////// 
void BoundingBox::Rotate(glm::vec3 rotateTo) {
        if(rotate.x <= 100.1f && rotate.y <= 100.1f && rotate.z <= 100.1f) {
                rotate = rotate + glm::vec3(0.1f , 0.1f, 0.1f);
        }
        else {
                rotate = glm::vec3(0.1f, 0.1f, 0.1f);
        }
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Scale Method
/// Controls the size of the Asset
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::Scale(glm::vec3 scaleTo) {
	if(scale.x < scaleTo.x && scale.y < scaleTo.y && scale.z < scaleTo.z) {
		scale = scale + glm::vec3(0.01f,0.01f,0.01f);
	}
	else {
		scale = glm::vec3(1.0f,1.0f,1.0f);
	}
}    

//////////////////////////////////////////////////////////////////////////////////////////
/// GetAABB
/// Gets the maximum and minimum AABB
//////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 BoundingBox::GetAABB(string check)
{
    if( AssetType != "Grass") {
        if (check == "Max") {
                AABB = translateTo += glm::vec3(1.0f,1.0f,1.0f) * scale;
        }
        else if (check == "Min") {
                AABB = translateTo += glm::vec3(-1.0f,-1.0f,-1.0f) * scale;
        }
    }
    return AABB;
}
//////////////////////////////////////////////////////////////////////////////////////////
/// CollisionDetection
/// Calculates whether BB1 AABB is within BB2 AABB and then move them back to there 
/// original starting xyz position
//////////////////////////////////////////////////////////////////////////////////////////
void BoundingBox::CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos,
                                     glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos) {
    if (BB1_Max.x > BB2_Min.x && BB1_Min.x < BB2_Max.x &&
        BB1_Max.y > BB2_Min.y && BB1_Min.y < BB2_Max.y &&
        BB1_Max.z > BB2_Min.z && BB1_Min.z < BB2_Max.z) {
        
        cout << "*****************************************************" << endl;
        cout << "Block Collision" << endl;
        cout << "*****************************************************" << endl;
        
        translateTo = translateToSave;
        scale = scaleTo;
        rotate = rotateTo;
    }
}  

//////////////////////////////////////////////////////////////////////////////////////////
/// GetTranslateTo
/// Returns the Current position the BoundingBox is at
//////////////////////////////////////////////////////////////////////////////////////////
glm::vec3 BoundingBox::GetTranslateTo() {
	return translateTo;
}
//////////////////////////////////////////////////////////////////////////////////////////
/// GetTranslateBool
/// Returns the translate_bool bool to see if it is animated or not
//////////////////////////////////////////////////////////////////////////////////////////
bool BoundingBox::GetTranslateBool() {
	return translate_bool;
}
//////////////////////////////////////////////////////////////////////////////////////////
/// GetScaleBool
/// Returns the scale_bool bool to see if it is animated or not
//////////////////////////////////////////////////////////////////////////////////////////
bool BoundingBox::GetScaleBool() {
	return scale_bool;
}
//////////////////////////////////////////////////////////////////////////////////////////
/// GetRotateBools
/// Returns the GetRotateBool bool to see if it is animated or not
//////////////////////////////////////////////////////////////////////////////////////////
bool BoundingBox::GetRotateBool() {
	return rotate_bool;
}

