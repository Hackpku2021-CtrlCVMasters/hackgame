//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_ENTITY_H
#define PKU_GAME_CORE_ENTITY_H

#include "util/Vec3f.h"

class World;
class Entity
{
protected:
    World* world;
    Vec3f position;
public:
    explicit Entity(World&);
    virtual ~Entity();

    void tick();

    const Vec3f &getPosition() const;
    World& getWorld() const;
    void move(Vec3f const&);
};


#endif //PKU_GAME_CORE_ENTITY_H
