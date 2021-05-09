#ifndef OPEN_CRAFT_VEC3_H
#define OPEN_CRAFT_VEC3_H


class Vec3f
{
public:
    float x, y, z;

    Vec3f() : x(0), y(0), z(0) {}

    Vec3f(float x, float y, float z) : x(0), y(0), z(0) {}

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
};


#endif //OPEN_CRAFT_VEC3_H
