#ifndef OPEN_CRAFT_AABB_H
#define OPEN_CRAFT_AABB_H

#include "Vec3.h"

class AABB
{
public:
    Vec3 p1, p2;
public:
    AABB() = default;

    AABB(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z) {}

    AABB(Vec3 const &p_1, Vec3 const &p_2)
    {
        p1 = p_1;
        p2 = p_2;
    }

    Vec3 getP1() const { return p1; }

    Vec3 getP2() const { return p2; }

    void setP1(Vec3 const &p) { p1 = p; }

    void setP2(Vec3 const &p) { p2 = p; }

    bool collideWith(AABB const &) const;

    bool collideWith(AABB const &, Vec3 const &) const;

    bool in(Vec3 const &) const;
};


#endif //OPEN_CRAFT_AABB_H
