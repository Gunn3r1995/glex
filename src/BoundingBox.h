#include <memory>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

class BoundingBox{
	public:
		BoundingBox(float x, float y, float z);
		glm::mat4 GetTranslationMatrix();

	private:
		float x;
		float y;
		float z;

		glm::mat4 translate_matrix;

};
