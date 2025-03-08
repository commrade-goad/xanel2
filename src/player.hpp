#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "object.hpp"

struct Player : public Object {
public:
    Vector2 speed;
    size_t maxSpeed;
    Texture2D* text;

    Player();
    Player(size_t maxSpeed, Texture2D* txt);
    Player(size_t maxSpeed, Rectangle rec, size_t z_index);
    // virtual just tell the compiler that it can be overwritten by the same function that have diff body
    virtual ~Player();
    void render();
    void logic(float dt);
};

#endif // PLAYER_HPP_
