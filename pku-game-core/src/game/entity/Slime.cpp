//
// Created by listerily on 5/9/21.
//

#include "Slime.h"

#include "../world/World.h"
#include "Player.h"
#include "../path/Pathfinder.h"

#include <cmath>

void Slime::tick()
{
    Entity::tick();

    if(world->getPlayer()->getPosition().getDistance(position) <= 1.0f)
    {
        world->getPlayer()->damage(1);
    }

    if(actionProcess == ActionProcess::READY)
    {
        Pathfinder finder(position, world->getPlayer()->getPosition());
        targetJumpPosition = finder.get(*world);
        fromJumpPosition = position;
        targetRotatingAngel = (float)atan(-(position.z - targetJumpPosition.z) / (position.x - targetJumpPosition.x));
        actionProcess = ActionProcess::ROTATE;
        jumpProcess = 0.0f;
        rotateAngel = (targetRotatingAngel - facing) / 20.0f;
    }
    else if(actionProcess == ActionProcess::ROTATE)
    {
        rotate();
    }
    else if(actionProcess == ActionProcess::JUMP)
    {
        jump();
    }
}

Slime::Slime(World &world) : Entity(world){
    facing = 1.0;
    actionProcess = ActionProcess::READY;
    targetJumpPosition = Vec3f();
    targetRotatingAngel = 0.0f;
    fromJumpPosition = Vec3f();
    jumpProcess = 0.0f;
    rotateAngel = 0.0f;
}

int Slime::getTypeId() const
{
    return Slime::TYPE_ID;
}

float Slime::getSize() const
{
    return 0.4;
}

float Slime::getFacing() const
{
    return facing + (float)M_PI / 2.0f;
}

float Slime::getHeight()
{
    return 0.6;
}

void Slime::rotate()
{
    facing += rotateAngel;

    if(facing - targetRotatingAngel <= 0.2f && facing - targetRotatingAngel >= -0.2f)
    {
        actionProcess = ActionProcess::JUMP;
        facing = targetRotatingAngel;
    }
}

void Slime::jump()
{
    if(jumpProcess >= 1.0f)
    {
        actionProcess = ActionProcess::READY;
        setPos(targetJumpPosition);
    }
    else
    {
        jumpProcess += 0.009f;
        float deltaX = -fromJumpPosition.x + targetJumpPosition.x;
        float deltaZ = -fromJumpPosition.z + targetJumpPosition.z;
        float thisX = fromJumpPosition.x + deltaX * jumpProcess;
        float thisZ = fromJumpPosition.z + deltaZ * jumpProcess;
        if(jumpProcess <= 0.5)
        {
            float deltaY = std::max(fromJumpPosition.y, targetJumpPosition.y) + 2.0f - fromJumpPosition.y;
            float thisY = fromJumpPosition.y + std::abs(jumpProcess - 0.0f) * 2.0f * deltaY;
            setPos({thisX, thisY, thisZ});
        }
        else
        {
            float deltaY = std::max(fromJumpPosition.y, targetJumpPosition.y) + 2.0f - targetJumpPosition.y;
            float thisY = targetJumpPosition.y + std::abs(jumpProcess - 1.0f) * 2.0f * deltaY;
            setPos({thisX, thisY, thisZ});
        }
    }
}

bool Slime::influencedByGravity() const
{
    return false;
}
