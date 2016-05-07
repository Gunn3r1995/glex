#include "GameAsset.h"

GameAsset::GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                     glm::vec3 animateTo, bool translate_bool, 
                     glm::vec3 rotate, bool rotate_bool,
                     glm::vec3 scale, bool scale_bool) {
        //////////////////////////////////////////////////////////////////////////////////////////
        /// Send Data To Bounding Box
        /// This Method Sends all the Data from spawning the Asset and sends it to the Bounding Box
        /// Class to create the Bounding Box and Manipulate the Asset
        ////////////////////////////////////////////////////////////////////////////////////////// 

	Bounding_Box = std::make_shared<BoundingBox>(xyzPosition, translateTo, 
                                                     animateTo, translate_bool, 
                                                     rotate, rotate_bool, 
                                                     scale, scale_bool);
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

glm::vec3 GameAsset::GetTranslateTo(){
    return Bounding_Box->GetTranslateTo();
}
