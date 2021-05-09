#ifndef OPEN_CRAFT_VEC3_H
#define OPEN_CRAFT_VEC3_H


class Vec3i
{
public:
    int x, y, z;

    Vec3i() : x(0), y(0), z(0) {}

    Vec3i(int x, int y, int z) : x(0), y(0), z(0) {}

    Vec3i operator+(Vec3i const &v) const { return {x + v.x, y + v.y, z + v.z}; }

    Vec3i &operator+=(Vec3i const &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3i operator-(Vec3i const &v) const { return {x - v.x, y - v.y, z - v.z}; }

    Vec3i &operator-=(Vec3i const &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    bool operator<(Vec3i const& v) const
    {
        if(x != v.x)
            return x < v.x;
        if(y != v.y)
            return y < v.y;
        return z < v.z;
    }

    bool operator>(Vec3i const& v) const
    {
        if(x != v.x)
            return x > v.x;
        if(y != v.y)
            return y > v.y;
        return z > v.z;
    }

    bool operator==(Vec3i const& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(Vec3i const& v) const
    {
        return x != v.x || y != v.y || z != v.z;
    }
};


#endif //OPEN_CRAFT_VEC3_H
