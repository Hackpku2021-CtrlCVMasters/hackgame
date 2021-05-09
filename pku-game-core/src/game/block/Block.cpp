//
// Created by listerily on 5/8/21.
//

#include "Block.h"

#include <utility>

Block::Block(std::string id, std::string texture) :
        texture(std::move(texture)), id(std::move(id))
{

}

Block::~Block()
{

}

const std::string &Block::getTexture() const
{
    return texture;
}

const std::string &Block::getId() const
{
    return id;
}