#include "Camera.h"
#include <glm/ext.hpp>
#include <iostream>
#include "GameAsset.h"

using namespace std;

Camera::Camera(){

}

glm::mat4 Camera::CameraUpdate(Movement movement, int Mouse_X, int Mouse_Y){

if(movement == STOPPED){
    cout<< "STOPPED" <<endl;
}

if(movement == UP ){
   cout << "UP" << endl;
}

}



