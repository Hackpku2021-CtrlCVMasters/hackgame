//
// Created by listerily on 5/9/21.
//

#ifndef PKU_GAME_CORE_SLIME_H
#define PKU_GAME_CORE_SLIME_H

#include "Entity.h"

class Slime : public Entity
{
private:
    float facing;
public:
    explicit Slime(World&);

    void tick() override;

    int getTypeId() const override;

    float getFacing() const;

    float getSize() const;

    static const int TYPE_ID = 1;

    float getHeight();
};


#endif //PKU_GAME_CORE_SLIME_H
