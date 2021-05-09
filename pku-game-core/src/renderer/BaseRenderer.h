//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_BASERENDERER_H
#define PKU_GAME_CORE_BASERENDERER_H

class World;
class RenderEngine;
class BaseRenderer
{
protected:
    RenderEngine* renderEngine;
public:
    explicit BaseRenderer(RenderEngine&);
    virtual ~BaseRenderer();

protected:
    RenderEngine& getRenderEngine();
};


#endif //PKU_GAME_CORE_BASERENDERER_H
