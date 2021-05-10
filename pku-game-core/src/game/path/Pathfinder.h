//
// Created by listerily on 5/10/21.
//

#ifndef PKU_GAME_CORE_PATHFINDER_H
#define PKU_GAME_CORE_PATHFINDER_H

#include "util/Vec3i.h"
#include "util/Vec3f.h"

class World;
class Vec3f;
class Vec3i;
class Pathfinder
{
private:
    Vec3i pi1, pi2;
    Vec3f pf1, pf2;
public:
    Pathfinder(Vec3f const&, Vec3f const&);

    Vec3f get(World &world);
};


#endif //PKU_GAME_CORE_PATHFINDER_H
