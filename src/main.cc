#define GLEW_STATIC // Easier debugging
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

using namespace std;

#include <boost/program_options.hpp>

#define RUN_GRAPHICS_DISPLAY 0x00;

#include "common.h"
#include "GameWorld.h"
#include "Camera.h"

/*
 * SDL timers run in separate threads.  In the timer thread
 * push an event onto the event queue.  This event signifies
 * to call display() from the thread in which the OpenGL 
 * context was created.
 */
Uint32 tick(Uint32 interval, void *param) {
  SDL_Event event;
  event.type = SDL_USEREVENT;
  event.user.code = RUN_GRAPHICS_DISPLAY;
  event.user.data1 = 0;
  event.user.data2 = 0;
  SDL_PushEvent(&event);
  return interval;
}

struct SDLWindowDeleter {
  inline void operator()(SDL_Window* window) {
    SDL_DestroyWindow(window);
  }
};

void Draw(const std::shared_ptr<SDL_Window> & window, const std::shared_ptr<GameWorld> & game_world) {
  glClearColor(0.0f, 206.0f, 250.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  game_world->Draw();

  // Don't forget to swap the buffers
  SDL_GL_SwapWindow(window.get());
}

std::shared_ptr<SDL_Window> InitWorld() {
  Uint32 width = 1980;//1280;
  Uint32 height = 1080;//720;
  SDL_Window * _window;
  std::shared_ptr<SDL_Window> window;
  

  // Glew will later ensure that OpenGL 3 *is* supported
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  // Do double buffering in GL
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
 
  // Initialise SDL - when using C/C++ it's common to have to
  // initialise libraries by calling a function within them.
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)<0) {
    std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  // When we close a window quit the SDL application
  atexit(SDL_Quit);

  // Create a new window with an OpenGL surface
  _window = SDL_CreateWindow("Shader Example"
                             , SDL_WINDOWPOS_CENTERED
                             , SDL_WINDOWPOS_CENTERED
                             , width
                             , height
                             , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (!_window) {
    std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  SDL_GLContext glContext = SDL_GL_CreateContext(_window);
  if (!glContext) {
    std::cout << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
    return nullptr;
  }

  // Initialise GLEW - an easy way to ensure OpenGl 3.0+
  // The *must* be done after we have set the video mode - otherwise we have no
  // OpenGL context to test.
  glewInit();
  if (!glewIsSupported("GL_VERSION_3_0")) {
    std::cerr << "OpenGL 3.0 not available" << std::endl;
    return nullptr;
  }

  // OpenGL settings
  glDisable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  window.reset(_window, SDL_DestroyWindow);
  return window;
}

ApplicationMode ParseOptions (int argc, char ** argv) {
  namespace po = boost::program_options;

  po::options_description desc("Allowed options");
  desc.add_options()
     ("help", "print this help message")
     ("translate", "Show translation example (default)")
     ("rotate", "Show rotation example")
     ("scale", "Show scale example")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if(vm.count("help")) {
    std::cout << desc << std::endl;
    exit(0);
  }

  if(vm.count("rotate")) {
    return ROTATE;
  }

  if(vm.count("scale")) {
    return SCALE;
  }
  // The default
  return TRANSFORM;
}
  int main(int argc, char ** argv) {
    Uint32 delay = 1000/30; // in milliseconds, Temporary change to 20fps to fix speed of the game.

        int X;
        int Y;

  auto mode = ParseOptions(argc, argv);
  auto window = InitWorld();
  auto game_world = std::make_shared<GameWorld>(mode);
  if(!window) {
    SDL_Quit();
  } 

  // Call the function "tick" every delay milliseconds
  SDL_AddTimer(delay, tick, NULL);

        cout << "****************************************************************************************" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                     Starting Game                                    *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*--------------------------------------------------------------------------------------*" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                               A simple Minecraft Like Game                           *" << endl;
        cout << "*                        With Block Spawing , Player Movement and                      *" << endl;
        cout << "*                                     Camera Control                                   *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*--------------------------------------------------------------------------------------*" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                    Work In Progress                                  *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*--------------------------------------------------------------------------------------*" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                       Controls                                       *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                 Player                                      Camera                   *" << endl;
        cout << "*                Forward                                        Up                     *" << endl;
        cout << "*                 _____                                        _____                   *" << endl;
        cout << "*                |     |                                      |     |                  *" << endl;
        cout << "*                |  w  |                                      |  ^  |                  *" << endl;
        cout << "*                |_____|                                      |_____|                  *" << endl;
        cout << "*          _____  _____  _____                          _____  _____  _____            *" << endl;
        cout << "*  Player |     ||     ||     | Player         Camera  |     ||     ||     | Camera    *" << endl;
        cout << "*   Left  |  a  ||  s  ||  d  |  Right          Left   |  <  ||  v  ||  >  |  Right    *" << endl;
        cout << "*         |_____||_____||_____|                        |_____||_____||_____|           *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                 Player                                       Camera                  *" << endl;
        cout << "*                Backwards                                      Down                   *" << endl;
        cout << "*                                      Mouse                                           *" << endl;
        cout << "*                                     _______                                          *" << endl;
        cout << "*                                    |    |   |                                        *" << endl;
        cout << "*                                   |     |    |                                       *" << endl;
        cout << "*                                  |      |     |                                      *" << endl;
        cout << "*                                  |      |     |                                      *" << endl;
        cout << "*                                 |              |                                     *" << endl;
        cout << "*                                 |              |                                     *" << endl;
        cout << "*                                 |              |                                     *" << endl;
        cout << "*                                  |            |                                      *" << endl;
        cout << "*                                   |          |                                       *" << endl;
        cout << "*                                    |________|                                        *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                          Camera Control Same as Arrow Keys                           *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                               Jump Up                         Drop Down              *" << endl;
        cout << "*           ______________________________________________     ___________             *" << endl;
        cout << "*          |                                              |   |           |            *" << endl;
        cout << "*          |                     Space                    |   | -->|(tab) |            *" << endl;
        cout << "*          |______________________________________________|   |___________|            *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                       Quit Game                                      *" << endl;
        cout << "*                                         _____                                        *" << endl;
        cout << "*                                        |     |                                       *" << endl;
        cout << "*                                        | esc |                                       *" << endl;
        cout << "*                                        |_____|                                       *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "*                                                                                      *" << endl;
        cout << "****************************************************************************************" << endl;
        cout << "" << endl;

	//SDL_SetRelativeMouseMode(SDL_TRUE);      
	//SDL_GetRelativeMouseState(&X, &Y);

        int Old_Mouse_X;
        int Old_Mouse_Y;

        int Mouse_X;
        int Mouse_Y;

  // Add the main event loop
  SDL_Event event;
  while (SDL_WaitEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      SDL_Quit();
      break;
    case SDL_USEREVENT:
      Draw(window, game_world);
      break;
    case  SDL_MOUSEMOTION:
      
        // save old mouse coordinates X
        Old_Mouse_X = Mouse_X;
        // get mouse coordinates X
        Mouse_X = event.motion.x;
        
      if (Mouse_X > Old_Mouse_X) {             // Mouse move Right
              game_world -> Camera_Control('>');
      }
      else if (Mouse_X < Old_Mouse_X) {        // Mouse move Left
              game_world -> Camera_Control('<');
      }
        // save old mouse coordinates Y
        Old_Mouse_Y = Mouse_Y;
        // get mouse coordinates Y
        Mouse_Y = event.motion.y;
      if (Mouse_Y < Old_Mouse_Y) {             // Mouse move Up 
              game_world -> Camera_Control('^');
      }
      else if (Mouse_Y > Old_Mouse_Y) {	// Mouse move Down
              game_world -> Camera_Control('v');
      }
      break;
    case SDL_KEYDOWN:			//At keyboard press
    switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:		 	//when pressing q
	SDL_Quit();			//Quit program
	cout << "Key 'q' Pressed, Game closed" << endl;
    break;
    case SDLK_w:			//When pressing w
        game_world -> Camera_Control('w');
      break;
    case SDLK_a:			//When pressing a
        game_world -> Camera_Control('a');
      break;
    case SDLK_s:			//When pressing s
        game_world -> Camera_Control('s');
      break;
    case SDLK_d:			//When pressing d
        game_world -> Camera_Control('d');
      break;
    case SDLK_UP:			//When pressing Arrow Up
        game_world -> Camera_Control('^');
      break;
    case SDLK_LEFT:			//When pressing Arrow Left
        game_world -> Camera_Control('<');
      break;
    case SDLK_DOWN:			//When pressing Arrow down
        game_world -> Camera_Control('v');
      break;
    case SDLK_RIGHT:			//When pressing Arrow right
        game_world -> Camera_Control('>');
      break;
    case SDLK_SPACE:
        game_world -> Camera_Control('+');
      break;
    case SDLK_TAB:
        game_world -> Camera_Control('-');
    default:
      break;
      }
    }
  }
}

