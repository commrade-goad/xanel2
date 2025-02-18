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

    bool operator==(const Object& other) const {
        return this->id == other.id;
    }

    Object();
    Object(Rectangle rec, int z_index);
    virtual ~Object();
    virtual void render();
};

struct ObjectManager {
public:
    std::unordered_map<int, std::vector<std::shared_ptr<Object>>> sortedData;
    size_t counter;

    ObjectManager();
    ~ObjectManager();

    void addObject(std::shared_ptr<Object> obj);
    void remObject(std::shared_ptr<Object> obj);
    void remObject(size_t id);
    /*std::shared_ptr<Object> getObject(size_t id);*/
};

#endif // OBJECT_HPP_
