#include "GameLoop.h"
//////////////////////////////////////////////////////////////////////////////////////////
/// Main Method
/// This method gets called when starting the game then calls the Run method in the
/// GameLoop class which is now able to be access by PythonBinding
//////////////////////////////////////////////////////////////////////////////////////////
int main(int argc,char ** argv) {
        shared_ptr<GameLoop> Game_Loop = make_shared<GameLoop>();
        Game_Loop->Run();
}
