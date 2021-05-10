//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_UIRENDERER_H
#define PKU_GAME_CORE_UIRENDERER_H

#include "BaseRenderer.h"

class UIRenderer : public BaseRenderer
{
public:
    explicit UIRenderer(RenderEngine&);
    void render(World &world);
};


#endif //PKU_GAME_CORE_UIRENDERER_H
