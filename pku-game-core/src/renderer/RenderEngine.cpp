//
// Created by listerily on 5/8/21.
//

#include "RenderEngine.h"

#include "BlockRenderer.h"
#include "MainApplication.h"
#include "game/GameClient.h"

RenderEngine::RenderEngine(MainApplication & application)
{
    app = &application;
    blockRenderer = new BlockRenderer();
}

RenderEngine::~RenderEngine()
{
    delete blockRenderer;
}

void RenderEngine::initialize()
{

}

void RenderEngine::render()
{
    blockRenderer->render(app->getGameClient().getWorld());
}
