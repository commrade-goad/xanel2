#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "object.hpp"

struct Player : public Object {
public:
    Vector2 speed;
    size_t maxSpeed;

    Player();
    Player(size_t maxSpeed);
    Player(size_t maxSpeed, Rectangle rec, size_t z_index);
    ~Player();
};

#endif // PLAYER_HPP_
