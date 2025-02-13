#ifndef GAME_HPP_
#define GAME_HPP_

#include "raylib.h"

struct Game {
private:
    Vector2 window_size;
    const char* name;
    // wil be removed later
    Rectangle player;

    void logic();
    void draw();
    void init();

public:
    Game(const char* name, Vector2 wsize);
    ~Game();
    void game_loop();
};

#endif // GAME_HPP_
