//
// Created by listerily on 5/9/21.
//

#ifndef PKU_GAME_CORE_TEXTUREMANAGER_H
#define PKU_GAME_CORE_TEXTUREMANAGER_H

#include <string>
#include <unordered_map>
#include <raylib.h>

class RenderEngine;
class TextureManager
{
private:
    std::unordered_map<std::string, Texture2D > textures;
    RenderEngine* engine;
public:
    explicit TextureManager(RenderEngine&);
    ~TextureManager();

    void initialize();

    const Texture2D* getTexture(std::string const& name) const;
};


#endif //PKU_GAME_CORE_TEXTUREMANAGER_H
