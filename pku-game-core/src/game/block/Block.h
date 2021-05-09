//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_BLOCK_H
#define PKU_GAME_CORE_BLOCK_H

#include <string>
#include <util/AABB.h>

class Block
{
private:
    std::string texture;
    std::string id;
public:
    Block(std::string  id, std::string  texture);
    virtual ~Block();

    virtual const std::string &getTexture() const;

    virtual const std::string &getId() const;

    virtual AABB getAABB() const;
};


#endif //PKU_GAME_CORE_BLOCK_H
