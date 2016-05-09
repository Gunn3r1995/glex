#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <GL/glew.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

using namespace std;

#include <boost/program_options.hpp>

#include "common.h"
#include "GameWorld.h"

class GameLoop {
        public:
                std::shared_ptr<SDL_Window> InitWorld();
                void Draw(const std::shared_ptr<SDL_Window> &window, const std::shared_ptr<GameWorld> &game_world);
                void Run();
  
        private:
};
#endif // GAMELOOP_H
