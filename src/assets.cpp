#include "assets.hpp"
#include "raylib.h"

AssetsManager::AssetsManager() {
    // by default reserve 10
    this->data.reserve(10);
};

// if texture with that name didnt exist return nullptr
Texture2D* AssetsManager::CheckTexture(std::string& name) {
    for (auto& data: this->data) {
        if (data.first == name) {
            return &data.second;
        }
    }
    return nullptr;
};

void AssetsManager::loadAssets(std::string& name, std::string& img_path) {
    Texture2D* ctxt = this->CheckTexture(name);
    if (ctxt != nullptr) {
        return;
    }
    Texture2D txt = LoadTexture(img_path.c_str());
    this->data.insert_or_assign(name, txt);
    return;
}

void AssetsManager::unLoadTexture(std::string& name) {
    Texture2D* ctxt = this->CheckTexture(name);
    size_t idx = 0;
    if (ctxt != nullptr) {
        for (auto& data: this->data) {
            if (data.first == name) {
                UnloadTexture(data.second);
                break;
            }
            idx++;
        }
        this->data.erase(name);
    }
}

AssetsManager::~AssetsManager() {
    for (auto& data: this->data) {
        UnloadTexture(data.second);
    }
};
