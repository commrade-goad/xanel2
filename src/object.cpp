#include "object.hpp"
#include "raylib.h"
#include <iostream>

// OBJECT

Object::Object() {}

Object::Object(Rectangle rec, int z_index, size_t id) {
    this->rec = rec;
    this->z_index = z_index;
    this->id = id;
}

Object::~Object() {}

void Object::render() {
    DrawRectangleRec(this->rec, BLACK);
}

// OBJECT MANAGER
// TODO: add sync to resync the sortedData with the new z-index.

ObjectManager::ObjectManager() {
    this->sortedData.reserve(10);
}

ObjectManager::~ObjectManager() {}

void ObjectManager::addObject(std::shared_ptr<Object> obj) {
    this->sortedData[obj->z_index].push_back(obj);
}

void ObjectManager::remObject(std::shared_ptr<Object> obj) {
    auto ur_pos = this->sortedData.find(obj->z_index);
    if (ur_pos != this->sortedData.end()) {
        std::vector<std::shared_ptr<Object>>& sdata = this->sortedData[obj->z_index];
        auto a_pos = std::ranges::find(sdata.begin(), sdata.end(), obj);
        if (a_pos != sdata.end()) {
            sdata.erase(a_pos);
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
