//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_WORLD_H
#define PKU_GAME_CORE_WORLD_H

#include <set>
#include <memory>
#include <unordered_map>
#include <random>

#include "util/Vec3i.h"

class GameClient;
class Entity;
class Block;
class Player;
class World
{
    friend class WorldGenerator;
private:
    std::set<std::unique_ptr<Entity> > entities;
    std::unordered_map<Vec3i, std::unique_ptr<Block> > blocks;
    Player* player;
    GameClient* gameClient;
    int worldSize{};
    long long seed{};
    std::set<Entity*> entitiesToBeRemoved;
public:
    explicit World(GameClient&);
    ~World();

    const std::set<std::unique_ptr<Entity> > &getEntities() const;

    const std::unordered_map<Vec3i, std::unique_ptr<Block> > &getBlocks() const;

    void addEntity(std::unique_ptr<Entity>);

    void addPlayer(std::unique_ptr<Player>);

    Block* getBlockAt(int, int, int);

    Player* getPlayer();

    void setBlock(int, int, int, std::unique_ptr<Block>);

    void removeBlock(int, int, int);

    void removeEntity(Entity*);

    void tick();

    bool hasFood() const;

    void generateFood();

    int getWorldSize() const;

    void setSeed(long long s);

    void markForRemove(Entity*);

    int getTargetScore() const;
};


#endif //PKU_GAME_CORE_WORLD_H
