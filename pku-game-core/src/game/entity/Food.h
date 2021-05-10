//
// Created by listerily on 5/10/21.
//

#ifndef PKU_GAME_CORE_FOOD_H
#define PKU_GAME_CORE_FOOD_H


#include "Entity.h"

class Food : public Entity
{
private:
    float rotation;
public:
    explicit Food(World&);

    float getRotation() const;

    void tick() override;

    int getTypeId() const override;

    static const int TYPE_ID = 2;
};


#endif //PKU_GAME_CORE_FOOD_H
