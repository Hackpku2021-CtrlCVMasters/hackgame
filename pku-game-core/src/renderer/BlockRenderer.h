//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_BLOCKRENDERER_H
#define PKU_GAME_CORE_BLOCKRENDERER_H

#include "BaseRenderer.h"

class BlockRenderer : public BaseRenderer
{
private:

public:
    explicit BlockRenderer(RenderEngine&);
    void render(World &world);
};


#endif //PKU_GAME_CORE_BLOCKRENDERER_H
