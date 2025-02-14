#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <unordered_map>
#include <vector>
#include "raylib.h"

struct Object {
public:
    size_t id;
    Rectangle rec;
    int z_index;
    Vector2 speed;

    bool operator==(const Object& other) const {
        return this->id == other.id;
            /*this->z_index == other.z_index &&*/
            /*this->rec.x == other.rec.x &&*/
            /*this->rec.y == other.rec.y;*/
    }

    Object(Rectangle rec, int z_index);
    ~Object();
    void render();
};

struct ObjectManager {
public:
    std::vector<Object> data;
    std::unordered_map<int, std::vector<Object*>> sortedData;

    ObjectManager();
    ~ObjectManager();

    void appendObject(Object obj);
    void addObject(Object* obj);
    void remObject(Object* obj);
    void remObject(size_t id);
};

#endif // OBJECT_HPP_
