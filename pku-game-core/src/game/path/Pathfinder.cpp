//
// Created by listerily on 5/10/21.
//

#include "Pathfinder.h"

#include "util/Vec3f.h"
#include "../world/World.h"

#include <queue>
#include <set>
#include <map>

Pathfinder::Pathfinder(const Vec3f & p1, const Vec3f & p2)
{
    pf1 = p1;
    pf2 = p2;
    pi1 = {(int)p1.x, (int)p1.y, (int)p1.z};
    pi2 = {(int)p2.x, (int)p2.y, (int)p2.z};
}

Vec3f Pathfinder::get(World &world)
{
    using namespace std;

    float deltaX = (pf2.x - pf1.x);
    float deltaZ = (pf2.z - pf1.z);
    if(deltaX <= 1.0f && deltaZ <= 1.0f && deltaX >= -1.0f && deltaZ >= -1.0f)
        return pf2;

    float x = pf1.x + 3.0f * deltaX / (float)sqrt(pow(deltaX, 2) + pow(deltaZ, 2));
    float z = pf1.z + 3.0f * deltaZ / (float)sqrt(pow(deltaX, 2) + pow(deltaZ, 2));
    int height = 0;
    for(int i = 50; i >= 0; --i)
    {
        if(world.getBlockAt((int)x, i, (int)z))
        {
            height = i;
            break;
        }
    }
    return Vec3f{x, (float)height + 1, z};
}
