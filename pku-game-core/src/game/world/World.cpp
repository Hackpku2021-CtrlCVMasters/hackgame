//
// Created by listerily on 5/8/21.
//

#include "World.h"

#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../block/Block.h"
#include "util/Vec3.h"

const std::vector<std::unique_ptr<Entity> > &World::getEntities() const
{
    return entities;
}

const std::map<Vec3, std::unique_ptr<Block>> &World::getBlocks() const
{
    return blocks;
}

World::World(GameClient & client)
{
    gameClient = &client;
    player = nullptr;
}

World::~World()
{

}

void World::addEntity(std::unique_ptr<Entity> entity)
{
    entities.push_back(std::move(entity));
}

Block *World::getBlockAt(int x, int y, int z)
{
    return nullptr;
}

Player *World::getPlayer()
{
    return player;
}

void World::addPlayer(std::unique_ptr<Player> p)
{
    player = p.get();
    addEntity(std::move(p));
}

void World::setBlock(int x, int y, int z, std::unique_ptr<Block> block)
{
    blocks[Vec3(x, y, z)] = std::move(block);
}

void World::removeBlock(int x, int y, int z)
{
    blocks[Vec3(x, y, z)] = nullptr;
}

void World::tick()
{
    for(auto& entity : entities)
    {
        entity->tick();
    }
}
