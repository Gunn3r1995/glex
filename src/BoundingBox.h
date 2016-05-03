#ifndef BOUNDINDBOX_H
#define BOUNDINGBOX_H

#include <memory>
#include <iostream>
#include <utility>
#include <ostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

class BoundingBox {
	public:
		BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                            glm::vec3 animateTo, bool translate_bool, 
                            glm::vec3 rotate, bool rotate_bool,
                            glm::vec3 scale, bool scale_bool);
		glm::mat4 GetTranslationMatrix();
                glm::mat4 GetModel();

                void Translate(glm::vec3 translate);
                void Rotate(glm::vec3 rotate);
                void Scale(glm::vec3 scale);
                glm::vec3 GetTranslateTo();
	private:
                glm::vec3 xyzPosition;
                glm::vec3 translateTo;
                glm::vec3 translateToSave;
                bool translate_bool;
                glm::vec3 trajectory;

                glm::vec3 rotate;
                glm::vec3 rotateTo;
                bool rotate_bool;                
        
                glm::vec3 scale;
                glm::vec3 scaleTo;
                bool scale_bool;
                

		glm::mat4 Translate_Matrix;
                glm::mat4 Scale_Matrix;
                glm::mat4 Model_Matrix;
};

#endif //BOUNDINGBOX_H
