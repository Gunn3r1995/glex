#include "BoundingBox.h"

BoundingBox::BoundingBox(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

glm::mat4 BoundingBox::GetTranslationMatrix()
{
	translate_matrix = glm::translate(glm::mat4(), glm::vec3(-x, y, z));

	return translate_matrix;
}
