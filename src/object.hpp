#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <unordered_map>
#include <vector>
#include "raylib.h"
#include "def.hpp"

struct Object {
public:
    size_t id;
    Rectangle rec;
    int z_index;

    bool operator==(const Object& other) const {
        return this->id == other.id;
    }

    Object();
    Object(Rectangle rec, int z_index);
    virtual ~Object();
    virtual void render();
    virtual void logic(float dt);
};

struct ObjectManager {
public:
    std::unordered_map<int, std::vector<sptr_t<Object>>> sortedData;
    size_t counter;

    ObjectManager();
    ~ObjectManager();

    // addObject will return id
    size_t addObject(sptr_t<Object> obj);
    void remObject(sptr_t<Object> obj);
    void remObject(size_t id);
    sptr_t<Object> getObject(size_t id);
};

#endif // OBJECT_HPP_
