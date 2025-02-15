#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <unordered_map>
#include <vector>
#include <memory>
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
    std::unordered_map<int, std::vector<std::shared_ptr<Object>>> sortedData;

    ObjectManager();
    ~ObjectManager();

    std::shared_ptr<Object> addObject(std::shared_ptr<Object> obj);
    void remObject(std::shared_ptr<Object> obj);
    void remObject(size_t id);
    std::shared_ptr<Object> getObject(size_t id);
};

#endif // OBJECT_HPP_
