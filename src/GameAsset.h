#ifndef GAMEASSET_H
#define GAMEASSET_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "BoundingBox.h"

class GameAsset {
        public:
                //////////////////////////////////////////////////////////////////////////////////////////
                /// Current Assets Data
                /// This gets the current assets data ready to be sent to the Bounding Box Class
                ////////////////////////////////////////////////////////////////////////////////////////// 
                GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, 
                          glm::vec3 animateTo, bool translate_bool, 
                          glm::vec3 rotate, bool rotate_bool,
                          glm::vec3 scale, bool scale_bool, string AssetType);
                bool GetTranslateBool();
                bool GetScaleBool();
                bool GetRotateBool();
                virtual void Draw(GLuint) = 0;
                glm::vec3 GetAABB(string check);
                void CollisionDetection(glm::vec3 BB1_Max, glm::vec3 BB1_Min, glm::vec3 BB1_Pos,
                                        glm::vec3 BB2_Max, glm::vec3 BB2_Min, glm::vec3 BB2_Pos);

                glm::mat4 GetModel();
                glm::vec3 GetTranslateTo();

                void Translate(glm::vec3 translateTo);

        private:
                glm::vec3 translateTo;
                std::shared_ptr<BoundingBox> Bounding_Box;
};

#endif
