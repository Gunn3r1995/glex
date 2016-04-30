#include <memory>
#include <iostream>
#include <utility>
#include <ostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

class BoundingBox {
	public:
		BoundingBox(glm::vec3 xyzPosition, glm::vec3 translateTo);
		glm::mat4 GetTranslationMatrix();
                glm::mat4 GetModel();

                void Translate(glm::vec3 translateTo);
                glm::vec3 GetxyzPosition();
	private:
                glm::vec3 xyzPosition;
                glm::vec3 translateTo;
                glm::vec3 translateXYZ;

		glm::mat4 translate_matrix;
                glm::mat4 model_matrix;
};


