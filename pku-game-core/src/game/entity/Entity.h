//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_ENTITY_H
#define PKU_GAME_CORE_ENTITY_H

#include <util/AABB.h>
#include "util/Vec3f.h"
#include <optional>

class World;

class Entity
{
protected:
    World *world;
    Vec3f position;
    std::optional<AABB> aabb;
public:
    explicit Entity(World &);

    virtual ~Entity();

    virtual void tick();

    virtual const Vec3f &getPosition() const;

    virtual World &getWorld() const;

    virtual void move(Vec3f const &);

    const std::optional<AABB> &getAABB() const;

    virtual bool collideWithBlocks(Vec3f const& ) const;
};


#endif //PKU_GAME_CORE_ENTITY_H
