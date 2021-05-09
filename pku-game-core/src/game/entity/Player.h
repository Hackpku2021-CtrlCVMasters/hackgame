//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_PLAYER_H
#define PKU_GAME_CORE_PLAYER_H


#include "Entity.h"

class Player : public Entity
{
protected:
    float yaw, pitch;
    Vec3f controlledSpeed;
public:
    explicit Player(World &);

    void moveYaw(float offset);

    void movePitch(float offset);

    float getYaw() const;

    float getPitch() const;

    void tick() override;

    void setYaw(float yaw);

    void setPitch(float pitch);

    void setControlledSpeed(const Vec3f &speed);

    void moveByController();

    Vec3f getEyePos() const;

    bool influencedByGravity() const override;

    bool canJump() const;

    void jump();

    int getTypeId() const override;

    static const int TYPE_ID = 0;
};


#endif //PKU_GAME_CORE_PLAYER_H
