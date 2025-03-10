#include "assets.hpp"

AssetsManager::AssetsManager() {
    // by default reserve 10
    this->data.reserve(10);
};

// if texture with that name didnt exist return nullptr
Texture2D* AssetsManager::GetTexture(std::string name) {
    for (auto& data: this->data) {
        if (data.first == name) {
            return &data.second;
        }
    }
    return nullptr;
};

Texture2D* AssetsManager::loadAssets(std::string name, std::string img_path) {
    Texture2D* ctxt = this->GetTexture(name);
    if (ctxt != nullptr) {
        return nullptr;
    }
    Texture2D txt = LoadTexture(img_path.c_str());
    this->data.insert_or_assign(name, txt);
    return &this->data[name];
}

void AssetsManager::unLoadTexture(std::string name) {
    Texture2D* ctxt = this->GetTexture(name);
    if (ctxt != nullptr) {
        for (auto& data: this->data) {
            if (data.first == name) {
                UnloadTexture(data.second);
                break;
            }
        }
        this->data.erase(name);
    }
}

AssetsManager::~AssetsManager() {
    for (auto& data: this->data) {
        UnloadTexture(data.second);
    }
};
