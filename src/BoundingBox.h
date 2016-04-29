#include <memory>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

class BoundingBox{
	public:
		BoundingBox(glm::vec3 xyzPosition);
		glm::mat4 GetTranslationMatrix();
                glm::vec3 GetxyzPosition();

	private:
                glm::vec3 xyzPosition;

		glm::mat4 translate_matrix;

};
