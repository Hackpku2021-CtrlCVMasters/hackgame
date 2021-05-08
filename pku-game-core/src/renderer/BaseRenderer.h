//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_BASERENDERER_H
#define PKU_GAME_CORE_BASERENDERER_H

class World;
class BaseRenderer
{
public:
    virtual void render(World&) = 0;
};


#endif //PKU_GAME_CORE_BASERENDERER_H
