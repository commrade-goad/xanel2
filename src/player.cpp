#include "player.hpp"

Player::Player(size_t maxSpeed) {
    this->speed = {0, 0};
    this->maxSpeed = maxSpeed;
    this->rec = {.x = 0, .y = 0, .width = 100, .height = 100};
    this->z_index = 1;
};

Player::Player(size_t maxSpeed, Rectangle rec, size_t z_index) : Object(rec, z_index) {
    this->speed = {0, 0};
    this->maxSpeed = maxSpeed;
};


Player::~Player() {}
