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
    auto ur_pos = this->sortedData.find(obj->z_index);
    if (ur_pos != this->sortedData.end()) {
        auto& sdata = this->sortedData[obj->z_index];
        auto a_pos = std::ranges::find(sdata.begin(), sdata.end(), obj);
        if (a_pos != sdata.end()) {
            sdata.erase(a_pos);
        }
        auto& saved_data = this->data;
        auto dpos = std::ranges::find(saved_data.begin(), saved_data.end(), *obj);
        if (dpos != saved_data.end()) {
            saved_data.erase(dpos);
        }
    }
}

void ObjectManager::appendObject(Object obj) {
    this->data.push_back(obj);
    auto dptr = &this->data.back();
    dptr->id = this->data.size();
    this->addObject(dptr);
}
