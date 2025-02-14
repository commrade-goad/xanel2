#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <unordered_map>
#include <vector>
#include "raylib.h"

struct Object {
public:
    Rectangle rec;
    int z_index;

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
};

#endif // OBJECT_HPP_
