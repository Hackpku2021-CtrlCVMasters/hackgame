//
// Created by listerily on 5/8/21.
//

#include <cmath>
#include "Entity.h"

#include "game/world/World.h"
#include "game/block/Block.h"

void Entity::tick()
{
    if(influencedByGravity())
        gravityInfluencedFall();
}

Entity::Entity(World & world):world(&world)
{
    aabb = AABB();
    fallingSpeed = 0.0f;
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
        auto thisAABB = *aabb;
        thisAABB.move(position + offset);
        for(std::int32_t i = -5; i <= 5; ++i)
            for(std::int32_t j = - 5; j <= 5; ++j)
                for(std::int32_t k = -5; k <= 5; ++k)
                {
                    int x = i + (int)position.x;
                    int y = j + (int)position.y;
                    int z = k + (int)position.z;
                    auto* block = world->getBlockAt(x, y, z);
                    if(block)
                    {
                        auto const& blockAABB = block->getAABB();
                        if(thisAABB.collideWith(blockAABB, Vec3f{(float)x, (float)y, (float)z}))
                            return true;
                    }
                }
    }
    return false;
}

bool Entity::influencedByGravity() const
{
    return false;
}

void Entity::gravityInfluencedFall()
{
    fallingSpeed += getGravity();
    Vec3f fallingVector{0., -fallingSpeed, 0.};
    if(!collideWithBlocks(fallingVector))
        move(fallingVector);
    else
        fallingSpeed = 0.0f;
}

float Entity::getGravity() const
{
    return 0.005;
}
