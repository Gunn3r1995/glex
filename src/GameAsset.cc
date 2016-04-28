#include "GameAsset.h"

GameAsset::GameAsset(float positionX, float positionY, float positionZ)
{
	Bounding_Box = std::make_shared<BoundingBox>(positionX, positionY, positionZ);

        cout << "BoundingBox: " << positionX << ", " << positionY << ", " << positionZ << endl;

}

void GameAsset::Camera(float LeftBoundingBox, float RightBoundingBox, float TopBoundingBox, float BottomBoundingBox, float FrontBoundingBox, float BackBoundingBox)
{
        cout << "Bounding Box Left: "<< LeftBoundingBox<< endl;
        cout << "Bounding Box Right: "<< RightBoundingBox << endl;
        cout << "Bounding Box Top: "<< TopBoundingBox << endl;
        cout << "Bounding Box Bottom: "<< BottomBoundingBox << endl;
        cout << "Bounding Box Front: "<< FrontBoundingBox << endl;
        cout << "Bounding Box Back: "<< BackBoundingBox << endl;
        cout << "***************************************************" << endl;

}

glm::mat4 GameAsset::GetTranslationMatrix()
{
	return Bounding_Box->GetTranslationMatrix();
}
