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
    pitch = 1.;

    aabb = AABB({-.3, -.45, -.3}, {.3, 1.25, .3});
    health = 20;
}

void Player::setYaw(float yaw)
{
    Player::yaw = yaw;
}

void Player::setPitch(float pitch)
{
    Player::pitch = pitch;
}

void Player::tick()
{
    Entity::tick();

    moveByController();
}

void Player::setControlledSpeed(const Vec3f &speed)
{
    controlledSpeed = speed;
}

void Player::moveByController()
{
    Vec3f controlledSpeed1 = controlledSpeed;
    controlledSpeed1.x = 0;
    controlledSpeed1.y = 0;
    if(!collideWithBlocks(controlledSpeed1))
        move(controlledSpeed1);

    Vec3f controlledSpeed2 = controlledSpeed;
    controlledSpeed2.x = 0;
    controlledSpeed2.z = 0;
    if(!collideWithBlocks(controlledSpeed2))
        move(controlledSpeed2);

    Vec3f controlledSpeed3 = controlledSpeed;
    controlledSpeed3.z = 0;
    controlledSpeed3.y = 0;
    if(!collideWithBlocks(controlledSpeed3))
        move(controlledSpeed3);

    controlledSpeed = {0., 0., 0.};
}

Vec3f Player::getEyePos() const
{
    return {0, 1.2f, 0};
}

bool Player::influencedByGravity() const
{
    return true;
}

bool Player::canJump() const
{
    return collideWithBlocks(Vec3f{0, -0.02, 0});
}

void Player::jump()
{
    fallingSpeed = -0.3;
}

int Player::getTypeId() const
{
    return Player::TYPE_ID;
}

int Player::getScore() const
{
    return score;
}

void Player::addScore(int s)
{
    this->score += s;
}

void Player::setScore(int score)
{
    Player::score = score;
}

int Player::getHealth() const
{
    return health;
}

void Player::setHealth(int h)
{
    Player::health = h;
}
