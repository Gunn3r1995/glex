#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <string>

#include "common.h"
#include <iostream>
#include <string>

using namespace std;

class BoundingBox {
	public:
		BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                            glm::vec3 animateTo, bool translate_bool, 
                            glm::vec3 rotate, bool rotate_bool,
                            glm::vec3 scale, bool scale_bool, string AssetType);
                glm::mat4 GetModel();

                void TranslateX();
                void TranslateY();
                void TranslateZ();
                void Rotate(glm::vec3 rotate);
                void Scale(glm::vec3 scale);

                glm::vec3 GetTranslateTo();
                bool GetTranslateBool();
                bool GetScaleBool();
                bool GetRotateBool();
                glm::vec3 GetAABB(string check);
                void CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos,
                                        glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos);
	private:
                //////////////////////////////////////////////////////////////////////////////////////////
                ///Initalise Data 
                ///The below vectors and booleans initialise all the variables used in the bounding box
                ///class to calculate and animate the Bounding Box
                ////////////////////////////////////////////////////////////////////////////////////////// 
                glm::vec3 xyzPosition, translateTo, translateToSave, animateTo;
                bool translate_bool;

                glm::vec3 rotate, rotateTo;
                bool rotate_bool;                
        
                glm::vec3 scale, scaleTo;
                bool scale_bool;
                
                string AssetType;
                
		glm::mat4 Translate_Matrix, Scale_Matrix, Model_Matrix;
                
                glm::vec3 AABB;
};

#endif //BOUNDINGBOX_H
