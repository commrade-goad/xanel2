#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "object.hpp"

struct Player : public Object {
public:
    Vector2 speed;
    size_t maxSpeed;

    Player();
    Player(size_t maxSpeed, size_t id);
    Player(size_t maxSpeed, Rectangle rec, size_t z_index, size_t id);
    // virtual just tell the compiler that it can be overwritten by the same function that have diff body
    virtual ~Player();
    void render();
};

#endif // PLAYER_HPP_
