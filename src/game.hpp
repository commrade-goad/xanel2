#ifndef GAME_HPP_
#define GAME_HPP_

#include "raylib.h"
#include "object.hpp"
#include "player.hpp"

struct Game {
public:
    Vector2 window_size;
    const char* name;
    Camera2D cam;
    ObjectManager objman;
    sptr_t<Player> player;

    void logic(float dt);
    void draw();
    void processInput();
    void drawFromCamera();
    void init();

    Game(const char* name, Vector2 wsize);
    ~Game();
    void gameLoop();
};

#endif // GAME_HPP_
