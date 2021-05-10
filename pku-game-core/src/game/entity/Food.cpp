//
// Created by listerily on 5/10/21.
//

#include "Food.h"

#include "../world/World.h"
#include "Player.h"

Food::Food(World &world) : Entity(world){
    rotation = 0.0f;
}

float Food::getRotation() const
{
    return rotation;
}

void Food::tick()
{
    Entity::tick();

    rotation += 0.03;

    if(world->getPlayer()->getPosition().getDistance(position) <= 1.0f)
    {
        world->markForRemove(this);
        world->getPlayer()->addScore(1);
    }
}

int Food::getTypeId() const
{
    return Food::TYPE_ID;
}
