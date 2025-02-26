#include "object.hpp"
#include "raylib.h"
#include <cstdint>

// OBJECT

Object::Object() {}

Object::Object(Rectangle rec, int z_index) {
    this->rec = rec;
    this->z_index = z_index;
    this->id = SIZE_MAX;
}

Object::~Object() {}

void Object::render() {
    DrawRectangleRec(this->rec, BLACK);
}

// OBJECT MANAGER
// TODO: add sync to resync the sortedData with the new z-index.

ObjectManager::ObjectManager() {
    this->sortedData.reserve(10);
    this->counter = 0;
}

ObjectManager::~ObjectManager() {}

void ObjectManager::addObject(sptr_t<Object> obj) {
    this->counter += 1;
    obj->id = this->counter;
    this->sortedData[obj->z_index].push_back(obj);
}

void ObjectManager::remObject(sptr_t<Object> obj) {
    auto ur_pos = this->sortedData.find(obj->z_index);
    if (ur_pos != this->sortedData.end()) {
        std::vector<sptr_t<Object>>& sdata = this->sortedData[obj->z_index];
        auto a_pos = std::ranges::find(sdata.begin(), sdata.end(), obj);
        if (a_pos != sdata.end()) {
            sdata.erase(a_pos);
            this->counter -= 1;
        }
    }
}

void ObjectManager::remObject(size_t id) {
    for (auto [z_index, objects] : this->sortedData) {
        for (auto obj : objects) {
            if (obj->id == id) {
                this->remObject(obj);
                return;
            }
        }
    }
}
