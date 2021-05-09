//
// Created by listerily on 5/9/21.
//

#ifndef PKU_GAME_CORE_MOB_H
#define PKU_GAME_CORE_MOB_H

#include "Entity.h"

class Mob : public Entity
{
public:
    explicit Mob(World&);

    bool influencedByGravity() const override;
};


#endif //PKU_GAME_CORE_MOB_H
