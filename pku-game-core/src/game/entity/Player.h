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
public:
    explicit Player(World&);

    void moveYaw(float offset);
    void movePitch(float offset);
    float getYaw() const;
    float getPitch() const;

    void setYaw(float yaw);

    void setPitch(float pitch);
};


#endif //PKU_GAME_CORE_PLAYER_H
