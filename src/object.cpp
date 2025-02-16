#include "object.hpp"
#include "raylib.h"

// OBJECT

Object::Object() {}

Object::Object(Rectangle rec, int z_index) {
    this->rec = rec;
    this->z_index = z_index;
    size_t uniqueId = reinterpret_cast<size_t>(this);
    this->id = uniqueId;
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
    std::shared_ptr<Object> optr = this->getObject(id);
    if (optr) {
        this->remObject(optr);
    }
}

std::shared_ptr<Object> ObjectManager::getObject(size_t id) {
    for (auto& sdata : this->sortedData) {
        for (auto& obj : sdata.second) {
            if (obj->id == id) {
                return obj;
            }
        }
    }
    return nullptr;
}
