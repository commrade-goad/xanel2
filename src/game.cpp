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

void Game::logic() {
    // do something here.
}

void Game::draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangleRec(this->player, BLACK);

    EndDrawing();
}

void Game::init() {
    this->player = {
        .x = 0,
        .y = 0,
        .width = 100,
        .height = 100
    };
}

void Game::game_loop() {
    this->init();
    while (!WindowShouldClose()) {
        this->logic();
        this->draw();
    }
}

