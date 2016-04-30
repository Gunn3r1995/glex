#include <memory>
#include <iostream>
#include <utility>
#include <ostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

class BoundingBox {
	public:
		BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo, glm::vec3 rotate, glm::vec3 scale);
		glm::mat4 GetTranslationMatrix();
                glm::mat4 GetModel();

                void Translate(glm::vec3 translateTo);
                void Rotate(glm::vec3 rotate);
                void Scale(glm::vec3 scale);
                glm::vec3 GetxyzPosition();
	private:
                glm::vec3 xyzPosition;
                glm::vec3 translateTo;
                glm::vec3 rotate;
                glm::vec3 scale;

		glm::mat4 Translate_Matrix;
                glm::mat4 Scale_Matrix;
                glm::mat4 Model_Matrix;
};


