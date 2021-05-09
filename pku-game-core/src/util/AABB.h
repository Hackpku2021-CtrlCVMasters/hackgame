#ifndef OPEN_CRAFT_AABB_H
#define OPEN_CRAFT_AABB_H

#include "Vec3f.h"

class AABB
{
public:
    Vec3f p1, p2;
public:
    AABB() = default;

    AABB(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z) {}

    AABB(Vec3f const &p_1, Vec3f const &p_2)
    {
        p1 = p_1;
        p2 = p_2;
    }

    Vec3f getP1() const { return p1; }

    Vec3f getP2() const { return p2; }

    void setP1(Vec3f const &p) { p1 = p; }

    void setP2(Vec3f const &p) { p2 = p; }

    bool collideWith(AABB const &) const;

    bool collideWith(AABB const &, Vec3f const &) const;

    bool in(Vec3f const &) const;
};


#endif //OPEN_CRAFT_AABB_H
