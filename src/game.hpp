#ifndef GAME_HPP_
#define GAME_HPP_

#include "raylib.h"
#include "object.hpp"

struct Game {
public:
    Vector2 window_size;
    const char* name;
    Camera2D cam;
    ObjectManager objman;

    void logic();
    void draw();
    void drawFromCamera();
    void init();

    Game(const char* name, Vector2 wsize);
    ~Game();
    void game_loop();
};

#endif // GAME_HPP_
