#include "game.hpp"
#include "object.hpp"
#include "raylib.h"
#include <cmath>

#define CAMSPEED 90

Game::Game(const char* name, Vector2 wsize) {
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(wsize.x, wsize.y, name);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    this->name = name;
    this->window_size = wsize;
    this->player = nullptr;
}

Game::~Game() {
    CloseWindow();
}

void Game::logic(float dt) {
    // pan camera to player.
    Vector2 newCamPos = {
        .x = std::lerp(this->cam.target.x, this->player->rec.x, dt * CAMSPEED),
        .y = std::lerp(this->cam.target.y, this->player->rec.y, dt * CAMSPEED)
    };
    // TODO: make if the movement is 0.01f it will not move the cam
    this->cam.target = newCamPos;
    this->cam.offset = (Vector2){
        .x = (this->window_size.x - this->player->rec.width) / 2.0f,
        .y = (this->window_size.y - this->player->rec.height) / 2.0f,
    };
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

void Game::processInput() {
    if (IsKeyDown(KEY_W)) {

    }
    if (IsKeyDown(KEY_S)) {

    }
    if (IsKeyDown(KEY_D)) {

    }
    if (IsKeyDown(KEY_A)) {

    }
    // WILL BE REMOVED LATER
    if (IsKeyPressed(KEY_R)) {
        this->objman.remObject(this->player->id);
    }
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
    this->player = this->objman.appendObject(player);
}

void Game::gameLoop() {
    this->init();
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        this->processInput();
        this->logic(dt);
        this->draw();
    }
}

