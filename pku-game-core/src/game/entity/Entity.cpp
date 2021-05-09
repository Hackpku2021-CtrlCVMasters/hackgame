//
// Created by listerily on 5/8/21.
//

#include "Entity.h"

void Entity::tick()
{

}

Entity::Entity(World & world):world(&world)
{

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
