#include "game.hpp" 

int main() {
    Game g = Game("xanel2", {1280, 720});
    g.game_loop();
    return 0;
}
