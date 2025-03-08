#include "player.hpp"
#include "raylib.h"

Player::Player(size_t maxSpeed, Texture2D* txt) {
    this->speed = {0, 0};
    this->maxSpeed = maxSpeed;
    this->rec = {.x = 0, .y = 0, .width = 100, .height = 100};
    this->z_index = 1;
    this->text = txt;
};

Player::Player(size_t maxSpeed, Texture2D* txt, Rectangle rec, size_t z_index) : Object(rec, z_index) {
    this->speed = {0, 0};
    this->maxSpeed = maxSpeed;
    this->text = txt;
};

void Player::render() {
    DrawTexturePro(
        *this->text,
        (Rectangle) {
            0,
            0,
            static_cast<float>(this->text->width),
            static_cast<float>(this->text->height)
        },
        this->rec,
        (Vector2) {
            0,0
        },
        0.0f,
        WHITE
    );
}

void Player::logic(float dt) {
    if (std::abs(this->speed.x) + std::abs(this->speed.y) > this->maxSpeed) {
        this->speed.x /= 1.3;
        this->speed.y /= 1.3;
    }
    this->rec.x += std::clamp(this->speed.x, -(float)this->maxSpeed, (float)this->maxSpeed) * dt;
    this->rec.y += std::clamp(this->speed.y, -(float)this->maxSpeed, (float)this->maxSpeed) * dt;
    this->speed.x *= 0.2;
    this->speed.y *= 0.2;
}

Player::~Player() {}
