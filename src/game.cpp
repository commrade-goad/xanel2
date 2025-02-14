#include "game.hpp"
#include "object.hpp"
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

    // draw background
    ClearBackground(RAYWHITE);

    // draw from camera angle
    this->drawFromCamera();

    // draw hud if needed
    
    EndDrawing();
}

void Game::drawFromCamera() {
    BeginMode2D(this->cam);

    for (auto& [z_index, objects] : this->objman.sortedData) {
        for (auto& obj : objects) {
            obj->render();
        }
    }

    EndMode2D();
}

void Game::init() {
    this->objman = ObjectManager();
    // init camera
    this->cam = {
        .offset = {
            .x = 0,
            .y = 0
        },
        .target = {
            .x = 0,
            .y = 0
        },
        .rotation = 0.0f,
        .zoom = 1.0f,
    };
    Object player = Object(
        (Rectangle){
            .x = 0,
            .y = 0,
            .width = 100,
            .height = 100
        },
        1
    );
    this->objman.appendObject(player);
}

void Game::game_loop() {
    this->init();
    while (!WindowShouldClose()) {
        this->logic();
        this->draw();
    }
}

