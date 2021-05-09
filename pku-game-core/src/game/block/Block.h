//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_BLOCK_H
#define PKU_GAME_CORE_BLOCK_H

#include <string>

class Block
{
private:
    std::string texture;
    std::string id;
public:
    Block(std::string  id, std::string  texture);
    ~Block();

    const std::string &getTexture() const;

    const std::string &getId() const;
};


#endif //PKU_GAME_CORE_BLOCK_H
