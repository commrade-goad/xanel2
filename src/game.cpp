#include "game.hpp"
#include "raylib.h"

Game::Game(const char* name, Vector2 wsize) {
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(wsize.x, wsize.y, name);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    this->name = name;
    this->window_size = wsize;
}

Game::~Game() {
    CloseWindow();
}

void Game::game_loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}

