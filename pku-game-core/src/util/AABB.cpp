#include "AABB.h"

#include <algorithm>
#include <raylib.h>

bool AABB::collideWith(const AABB &rhs) const
{
    return CheckCollisionBoxes({{p1.x, p1.y, p1.z}, {p2.x, p2.y, p2.z}},
                               {{rhs.p1.x, rhs.p1.y, rhs.p1.z}, {rhs.p2.x, rhs.p2.y, rhs.p2.z}});
}

bool AABB::collideWith(const AABB &_o, const Vec3f &offset) const
{
    AABB o = {_o.p1 + offset, _o.p2 + offset};
    return collideWith(o);
}

void AABB::move(const Vec3f & v)
{
    p1 += v;
    p2 += v;
}
