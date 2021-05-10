//
// Created by listerily on 5/9/21.
//

#include "Slime.h"

void Slime::tick()
{
    Entity::tick();


}

Slime::Slime(World &world) : Entity(world){
    facing = 1.0;
    isJumping = false;
    isRotating = false;
    targetJumpPosition = Vec3f();
    targetRotatingAngel = 0.0f;
    fromJumpPosition = Vec3f();
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
    return facing;
}

float Slime::getHeight()
{
    return 0.6;
}

void Slime::rotate()
{

}

void Slime::jump()
{

}
