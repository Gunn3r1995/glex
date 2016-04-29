#include "BoundingBox.h"

BoundingBox::BoundingBox(glm::vec3 xyzPosition)
{
	this->xyzPosition = xyzPosition;

	//cout << "Bounding Box Created at: " << xyzPosition.x << endl;
}

glm::mat4 BoundingBox::GetTranslationMatrix()
{
	translate_matrix = glm::translate(glm::mat4(), glm::vec3(this->xyzPosition));

	return translate_matrix;
}

glm::vec3 BoundingBox::GetxyzPosition()
{
	return xyzPosition;
}
