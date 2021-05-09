//
// Created by listerily on 5/8/21.
//

#include <util/Vec3f.h>
#include <complex>
#include "RenderEngine.h"

#include "BlockRenderer.h"
#include "MainApplication.h"
#include "game/GameClient.h"
#include "texture/TextureManager.h"
#include "game/world/World.h"
#include "game/entity/Player.h"

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
    auto& world = app->getGameClient().getWorld();
    auto* player = world.getPlayer();
    Camera3D camera = { 0 };
    Vec3f cameraPosition = player->getPosition() + player->getEyePos();
    camera.position = (Vector3){ cameraPosition.x, cameraPosition.y, cameraPosition.z};
    float targetX = std::cos(player->getPitch()) * std::cos(player->getYaw());
    float targetY = std::sin(player->getPitch());
    float targetZ = std::cos(player->getPitch()) * std::sin(player->getYaw());
    targetX += cameraPosition.x;
    targetY += cameraPosition.y;
    targetZ += cameraPosition.z;
    camera.target = (Vector3){ targetX, targetY, targetZ };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_PERSPECTIVE);
    UpdateCamera(&camera);

    BeginDrawing();
    BeginMode3D(camera);

    blockRenderer->render(world);

    EndMode3D();
    EndDrawing();
}

TextureManager &RenderEngine::getTextureManager()
{
    return *textureManager;
}
