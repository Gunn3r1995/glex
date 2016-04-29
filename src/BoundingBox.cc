#include "BoundingBox.h"

BoundingBox::BoundingBox(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	cout << "Bounding Box Created at:  X: " << x << " Y: " << y << " Z: " << z << endl;
}

glm::mat4 BoundingBox::GetTranslationMatrix()
{
	translate_matrix = glm::translate(glm::mat4(), glm::vec3(-x, y, z));

	return translate_matrix;
}
