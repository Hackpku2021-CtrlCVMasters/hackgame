//
// Created by listerily on 5/8/21.
//

#include "Entity.h"

#include "game/world/World.h"
#include "game/block/Block.h"

void Entity::tick()
{

}

Entity::Entity(World & world):world(&world)
{
    aabb = AABB();
}

Entity::~Entity()
{

}

const Vec3f &Entity::getPosition() const
{
    return position;
}

World &Entity::getWorld() const
{
    return *world;
}

void Entity::move(const Vec3f & v)
{
    position += v;
}

const std::optional<AABB> &Entity::getAABB() const
{
    return aabb;
}

bool Entity::collideWithBlocks(Vec3f const& offset) const
{
    if(aabb.has_value())
    {
        auto const& blocks = world->getBlocks();
        auto thisAABB = *aabb;
        thisAABB.move(position + offset);
        for(auto const& block : blocks)
        {
            if(block.second == nullptr)
                continue;
            auto const& blockAABB = block.second->getAABB();
            if(thisAABB.collideWith(blockAABB, {(float)block.first.x, (float) block.first.y, (float)block.first.z}))
            {
                return true;
            }
        }
    }
    return false;
}
