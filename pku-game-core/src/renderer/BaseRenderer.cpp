//
// Created by listerily on 5/8/21.
//

#include "BaseRenderer.h"

BaseRenderer::BaseRenderer(RenderEngine & renderEngine) : renderEngine(&renderEngine)
{

}

BaseRenderer::~BaseRenderer() = default;

RenderEngine &BaseRenderer::getRenderEngine()
{
    return *renderEngine;
}
