//
// Created by listerily on 5/9/21.
//

#include "TextureManager.h"

#include <raylib.h>

#include <fstream>
#include <json/json.h>

TextureManager::TextureManager(RenderEngine & engine):engine(&engine)
{

}

TextureManager::~TextureManager() = default;

void TextureManager::initialize()
{
    using namespace Json;
    using namespace std;
    Value value;
    ifstream("../config/texture.json") >> value;
    for(auto const& t : value["textures"])
    {
        textures[t["name"].asString()] = LoadTexture(t["path"].asCString());
    }
}

const Texture2D *TextureManager::getTexture(const std::string &name) const
{
    if(textures.count(name) == 0)
        return nullptr;
    return &textures.at(name);
}
