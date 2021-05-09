#ifndef OPEN_CRAFT_VEC3_H
#define OPEN_CRAFT_VEC3_H

#include <unordered_map>


class Vec3i
{
public:
    int x{0}, y{0}, z{0};

    Vec3i operator+(Vec3i const &v) const { return Vec3i{x + v.x, y + v.y, z + v.z}; }

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

namespace std{
    template<>
    struct hash<Vec3i> {
        std::size_t operator() (const Vec3i &v)const{
            return std::hash<decltype(v.x)>{}(v.x) << 16 |
                   std::hash<decltype(v.x)>{}(v.x) << 8 |
                   std::hash<decltype(v.x)>{}(v.x);
        }
    };
}


#endif //OPEN_CRAFT_VEC3_H
