//
// Created by listerily on 5/9/21.
//

#include "Mob.h"

bool Mob::influencedByGravity() const
{
    return true;
}

Mob::Mob(World & world) : Entity(world){

}
