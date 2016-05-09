#include "GameLoop.h"

int main(int argc, char ** argv) {
        std::shared_ptr<GameLoop> Game_Loop = std::make_shared<GameLoop>();
        Game_Loop->Run();
}
