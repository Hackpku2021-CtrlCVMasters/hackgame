//
// Created by listerily on 5/8/21.
//

#include "World.h"

#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../entity/Food.h"
#include "../block/Block.h"
#include "util/Vec3i.h"

const std::set<std::unique_ptr<Entity> > &World::getEntities() const
{
    return entities;
}

const std::unordered_map<Vec3i, std::unique_ptr<Block>> &World::getBlocks() const
{
    return blocks;
}

World::World(GameClient &client)
{
    gameClient = &client;
    player = nullptr;
}

World::~World()
{

}

void World::addEntity(std::unique_ptr<Entity> entity)
{
    entities.insert(std::move(entity));
}

Block *World::getBlockAt(int x, int y, int z)
{
    return blocks[{x, y, z}].get();
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
    if(x < -worldSize || x >= worldSize)
        return;
    if(z < -worldSize || z >= worldSize)
        return;
    blocks[{x, y, z}] = std::move(block);
}

void World::removeBlock(int x, int y, int z)
{
    blocks[{x, y, z}] = nullptr;
}

void World::tick()
{
    for (auto *e : entitiesToBeRemoved)
        removeEntity(e);
    entitiesToBeRemoved.clear();

    for (auto &entity : entities)
        entity->tick();

    if (!hasFood())
        generateFood();
}

void World::removeEntity(Entity *entity)
{
    for (auto it = entities.begin(); it != entities.end(); ++it)
    {
        if ((*it).get() == entity)
        {
            it = entities.erase(it);
        }
    }
}

bool World::hasFood() const
{
    for (const auto &e : entities)
        if (e->getTypeId() == Food::TYPE_ID)
            return true;
    return false;
}

void World::generateFood()
{
    bool generated = false;
    while (!generated)
    {
        int x = (rand() % (getWorldSize() * 2)) - getWorldSize();
        int y = (rand() % (getWorldSize() * 2)) - getWorldSize();

        int height = -1;
        for (int i = 50; i >= 0; --i)
        {
            if (getBlockAt(x, i, y))
            {
                height = i;
                break;
            }
        }
        if (height == -1)
            continue;
        if (height <= 5)
        {
            generated = true;
            auto food = std::make_unique<Food>(*this);
            food->setPos({(float) x, (float) height + 1, (float) y});
            addEntity(std::move(food));
        }
    }
}

int World::getWorldSize() const
{
    return worldSize;
}

void World::setSeed(long long int s)
{
    seed = s;
}

void World::markForRemove(Entity *e)
{
    entitiesToBeRemoved.insert(e);
}

int World::getTargetScore() const
{
    return 8;
}

bool World::isWalkable(int, int) const
{
    return false;
}
