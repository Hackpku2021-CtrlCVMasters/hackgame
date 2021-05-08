//
// Created by listerily on 5/8/21.
//

#include "World.h"

#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../block/Block.h"

const std::vector<std::unique_ptr<Entity> > &World::getEntities() const
{
    return entities;
}

const std::vector<std::unique_ptr<Block> > &World::getBlocks() const
{
    return blocks;
}

World::World(GameClient & client)
{
    gameClient = &client;
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
