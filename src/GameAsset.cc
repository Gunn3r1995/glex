#include "GameAsset.h"
//////////////////////////////////////////////////////////////////////////////////////////
/// Send Data To Bounding Box
/// This Method Sends all the Data from spawning the Asset and sends it to the Bounding Box
/// Class to create the Bounding Box and Manipulate the Asset
////////////////////////////////////////////////////////////////////////////////////////// 
GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                     glm::vec3 animateTo, bool translate_bool, 
                     glm::vec3 rotate, bool rotate_bool,
                     glm::vec3 scale, bool scale_bool) 
                     : Bounding_Box (make_shared<BoundingBox>(xyzPosition, translateTo, 
                                                      animateTo, translate_bool, 
                                                      rotate, rotate_bool, 
                                                      scale, scale_bool)){


        //cout << "translateTO "<< glm::to_string(translateTo) <<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////
///Get Model
///This class Gets the Model from the Bounding Box class, This method is normally called
///by the Draw method in GameAssetManager
////////////////////////////////////////////////////////////////////////////////////////// 
glm::mat4 GameAsset::GetModel() {
	return Bounding_Box->GetModel();
}

glm::vec3 GameAsset::GetAABB(string check) {
    if(check == "Max") {
        return Bounding_Box->GetAABB("Max");
    }
    else if(check == "Min") {
        return Bounding_Box->GetAABB("Min");
    }
}

void GameAsset::CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos,
                                   glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos) {
    Bounding_Box->CollisionDetection(BB1_Max, BB1_Min, BB1_Pos, BB2_Max, BB2_Min, BB2_Pos);
}

//////////////////////////////////////////////////////////////////////////////////////////
///Get TranslateTo
///This class Gets the TranslateTo from the Bounding Box class, Which is the current Position
///of the Asset
////////////////////////////////////////////////////////////////////////////////////////// 
glm::vec3 GameAsset::GetTranslateTo(){
    return Bounding_Box->GetTranslateTo();
}

bool GameAsset::GetTranslateBool() {
    return Bounding_Box->GetTranslateBool();
}

bool GameAsset::GetScaleBool() {
        return Bounding_Box->GetScaleBool();
}

bool GameAsset::GetRotateBool() {
        return Bounding_Box->GetRotateBool();
}

