#ifndef OPEN_CRAFT_VEC3F_H
#define OPEN_CRAFT_VEC3F_H

#include <cmath>

class Vec3f
{
public:
    float x{0}, y{0}, z{0};

    Vec3f operator+(Vec3f const &v) const { return {x + v.x, y + v.y, z + v.z}; }

    Vec3f &operator+=(Vec3f const &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3f operator-(Vec3f const &v) const { return {x - v.x, y - v.y, z - v.z}; }

    Vec3f &operator-=(Vec3f const &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    bool operator<(Vec3f const& v) const
    {
        if(x != v.x)
            return x < v.x;
        if(y != v.y)
            return y < v.y;
        return z < v.z;
    }

    bool operator>(Vec3f const& v) const
    {
        if(x != v.x)
            return x > v.x;
        if(y != v.y)
            return y > v.y;
        return z > v.z;
    }

    bool operator==(Vec3f const& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    float getDistance(Vec3f const& v) const
    {
        return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
    }
};


#endif //OPEN_CRAFT_VEC3F_H
