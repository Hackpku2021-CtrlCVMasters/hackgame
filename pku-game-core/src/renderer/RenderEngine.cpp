//
// Created by listerily on 5/8/21.
//

#include "RenderEngine.h"

#include "BlockRenderer.h"
#include "MainApplication.h"
#include "game/GameClient.h"
#include "texture/TextureManager.h"

RenderEngine::RenderEngine(MainApplication & application)
{
    app = &application;
    textureManager = new TextureManager(*this);

    blockRenderer = new BlockRenderer(*this);
}

RenderEngine::~RenderEngine()
{
    delete textureManager;
    delete blockRenderer;
}

void RenderEngine::initialize()
{
    textureManager->initialize();
}

void RenderEngine::render()
{
    blockRenderer->render(app->getGameClient().getWorld());
}

TextureManager &RenderEngine::getTextureManager()
{
    return *textureManager;
}
