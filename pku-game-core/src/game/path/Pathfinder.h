//
// Created by listerily on 5/10/21.
//

#ifndef PKU_GAME_CORE_PATHFINDER_H
#define PKU_GAME_CORE_PATHFINDER_H


class World;
class Vec3f;
class Pathfinder
{
public:
    Pathfinder(Vec3f const&, Vec3f const&);

    Vec3f get(World &world);
};


#endif //PKU_GAME_CORE_PATHFINDER_H
