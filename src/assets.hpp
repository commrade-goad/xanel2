#ifndef ASSETS_HPP_
#define ASSETS_HPP_
#include "raylib.h"
#include <string>
#include <unordered_map>

struct AssetsManager {
public:
    std::unordered_map<std::string, Texture2D> data;

    AssetsManager();
    ~AssetsManager();

    void loadAssets(std::string name, std::string img_path);
    Texture2D* GetTexture(std::string name);
    void unLoadTexture(std::string name);
};

#endif // ASSETS_HPP_
