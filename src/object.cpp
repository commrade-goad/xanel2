#include "object.hpp"
#include "raylib.h"

// OBJECT

Object::Object(Rectangle rec, int z_index) {
    this->rec = rec;
    this->z_index = z_index;
}

Object::~Object() {}

// OBJECT MANAGER

ObjectManager::ObjectManager() {
    // reserve more if there is more data later.
    // less realloc more better.
    this->sortedData.reserve(10);
}

ObjectManager::~ObjectManager() {}

void ObjectManager::addObject(Object* obj) {
    this->sortedData[obj->z_index].push_back(obj);
}

void ObjectManager::remObject(Object* obj) {
    auto pos = this->sortedData.find(obj->z_index);
    if (pos != this->sortedData.end()) {
        auto& data = this->sortedData[obj->z_index];
        auto pos2 = std::ranges::find(data.begin(), data.end(), obj);
        if (pos2 != data.end()) {
            data.erase(pos2);
        }
    }
}
