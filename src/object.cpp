#include "object.hpp"
#include "raylib.h"

// OBJECT

Object::Object(Rectangle rec, int z_index) {
    this->rec = rec;
    this->z_index = z_index;
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

void ObjectManager::addObject(Object* obj) {
    this->sortedData[obj->z_index].push_back(obj);
}

void ObjectManager::remObject(Object* obj) {
    // TODO: remove the data from this->data too.
    auto ur_pos = this->sortedData.find(obj->z_index);
    if (ur_pos != this->sortedData.end()) {
        auto& sdata = this->sortedData[obj->z_index];
        auto a_pos = std::ranges::find(sdata.begin(), sdata.end(), obj);
        if (a_pos != sdata.end()) {
            sdata.erase(a_pos);
        }
    }
}

void ObjectManager::appendObject(Object obj) {
    this->data.push_back(obj);
    this->addObject(&this->data.back());
}
