#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <iostream>

using namespace std;

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif __linux__
#include <GL/gl.h>
#else
#   error "Unknown compiler"
#endif

#include "BoundingBox.h"

class GameAsset {
        public:
                GameAsset(glm::vec3 xyzPosition, glm::vec3 translateTo, bool translate_bool, 
                          glm::vec3 rotate, bool rotate_bool,
                          glm::vec3 scale, bool scale_bool);
                virtual void Draw(GLuint) = 0;

                glm::mat4 GetModel();

                void Translate(glm::vec3 translateTo);

        private:
                glm::vec3 translateTo;
                std::shared_ptr<BoundingBox> Bounding_Box;

};

#endif
