//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_WORLD_H
#define PKU_GAME_CORE_WORLD_H

#include <vector>
#include <memory>
#include <map>

#include "util/Vec3.h"

class GameClient;
class Entity;
class Block;
class Player;
class World
{
private:
    std::vector<std::unique_ptr<Entity> > entities;
    std::map<Vec3, std::unique_ptr<Block> > blocks;
    Player* player;
    GameClient* gameClient;
public:
    explicit World(GameClient&);
    ~World();

    const std::vector<std::unique_ptr<Entity> > &getEntities() const;

    const std::map<Vec3, std::unique_ptr<Block> > &getBlocks() const;

    void addEntity(std::unique_ptr<Entity>);

    void addPlayer(std::unique_ptr<Player>);

    Block* getBlockAt(int, int, int);

    Player* getPlayer();

    void setBlock(int, int, int, std::unique_ptr<Block>);

    void removeBlock(int, int, int);

    void tick();
};


#endif //PKU_GAME_CORE_WORLD_H
