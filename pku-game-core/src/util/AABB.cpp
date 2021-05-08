#include "AABB.h"

#include <algorithm>

bool AABB::collideWith(const AABB &o) const
{
    float min_x, min_y, min_z;
    float max_x, max_y, max_z;
    min_x = std::min(o.p1.x, o.p2.x);
    min_y = std::min(o.p1.y, o.p2.y);
    min_z = std::min(o.p1.z, o.p2.z);
    max_x = std::max(o.p1.x, o.p2.x);
    max_y = std::max(o.p1.y, o.p2.y);
    max_z = std::max(o.p1.z, o.p2.z);
    return in({min_x, min_y, min_z}) || in({max_x, min_y, min_z}) || in({min_x, max_y, min_z}) ||
           in({min_x, min_y, max_z}) ||
           in({max_x, min_y, max_z}) || in({max_x, max_y, min_z}) || in({min_x, max_y, max_z}) ||
           in({max_x, max_y, max_z});
}

bool AABB::collideWith(const AABB &_o, const Vec3 &offset) const
{
    AABB o = {_o.p1 + offset, _o.p2 + offset};
    return collideWith(o);
}

bool AABB::in(const Vec3 &p) const
{
    float min_x, min_y, min_z;
    float max_x, max_y, max_z;
    min_x = std::min(p1.x, p2.x);
    min_y = std::min(p1.y, p2.y);
    min_z = std::min(p1.z, p2.z);
    max_x = std::max(p1.x, p2.x);
    max_y = std::max(p1.y, p2.y);
    max_z = std::max(p1.z, p2.z);
    return p.x >= min_x && p.x <= max_x && p.y >= min_y && p.y <= max_y && p.z >= min_z && p.z <= max_z;
}
