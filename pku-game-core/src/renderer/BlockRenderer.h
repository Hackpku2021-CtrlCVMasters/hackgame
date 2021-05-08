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
    void render(World &world) override;
};


#endif //PKU_GAME_CORE_BLOCKRENDERER_H
