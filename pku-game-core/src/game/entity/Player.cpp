//
// Created by listerily on 5/8/21.
//

#include "Player.h"

void Player::moveYaw(float offset)
{
    yaw += offset;
}

void Player::movePitch(float offset)
{
    pitch += offset;
}

float Player::getYaw() const
{
    return yaw;
}

float Player::getPitch() const
{
    return pitch;
}

Player::Player(World & world) : Entity(world){
    yaw = 0.;
    pitch = 0.;
}

void Player::setYaw(float yaw)
{
    Player::yaw = yaw;
}

void Player::setPitch(float pitch)
{
    Player::pitch = pitch;
}
