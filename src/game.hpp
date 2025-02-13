#ifndef GAME_HPP_
#define GAME_HPP_

#include "raylib.h"

struct Game {
    Vector2 window_size;
    const char* name;

    Game(const char* name, Vector2 wsize);
    ~Game();
    void game_loop();
};

#endif // GAME_HPP_
