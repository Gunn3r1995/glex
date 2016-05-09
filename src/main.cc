#include "GameLoop.h"

int main() {
        std::shared_ptr<GameLoop> Game_Loop = std::make_shared<GameLoop>();
        Game_Loop->Run();
}
