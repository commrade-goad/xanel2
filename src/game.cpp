#include "game.hpp"
#include "object.hpp"
#include "raylib.h"
#include "player.hpp"
#include <cmath>
#include <memory>

#define CAMSPEED 25

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
    if (this->player == nullptr) {
        return;
    }
    // pan camera to player.
    Vector2 newCamPos = {
        .x = std::lerp(this->cam.target.x, this->player->rec.x, dt * CAMSPEED),
        .y = std::lerp(this->cam.target.y, this->player->rec.y, dt * CAMSPEED)
    };

    static const float Tolerance = 0.02f;
    if (Tolerance > newCamPos.x || Tolerance > newCamPos.y) {
        this->cam.target = newCamPos;
        this->cam.offset = (Vector2){
            .x = (this->window_size.x - this->player->rec.width) / 2.0f,
            .y = (this->window_size.y - this->player->rec.height) / 2.0f,
        };
    } // maybe just teleport it idk...

    // player movement
    this->player->logic(dt);
    
    // TODO: add for loops for object vector to do stuff.
}

void Game::draw() {
    BeginDrawing();

    // draw background
    ClearBackground(RAYWHITE);

    // draw from camera angle
    this->drawFromCamera();

    // draw hud if needed
    DrawFPS(0, 0);

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
    if (this->player == nullptr) {
        return;
    }
    static const int SPEED = this->player->maxSpeed/2;
    // so this is the cpp way of doing `Player* p = (Player*)this->player`
    /*auto p = std::dynamic_pointer_cast<Player>(this->player);*/
    if (IsKeyDown(KEY_W)) {
        this->player->speed.y -= SPEED;
    }
    if (IsKeyDown(KEY_S)) {
        this->player->speed.y += SPEED;
    }
    if (IsKeyDown(KEY_D)) {
        this->player->speed.x += SPEED;
    }
    if (IsKeyDown(KEY_A)) {
        this->player->speed.x -= SPEED;
    }

    // EXAMPLE of removing object from objman
    /* if (IsKeyPressed(KEY_R)) {
          this->objman.remObject(this->player->id);
          this->player = nullptr;
    } */
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
    sptr_t<Player> player = std::make_shared<Player>(
        Player(500)
    );
    sptr_t<Object> bg = std::make_shared<Object>(
        Object((Rectangle){.x = 0, .y = 0, .width = 500, .height = 500}, 0)
    );
    this->objman.addObject(player);
    this->objman.addObject(bg);
    this->player = player;
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
