//
// Created by listerily on 5/8/21.
//

#include <raylib.h>
#include "BlockRenderer.h"

#include "game/world/World.h"
#include "game/block/Block.h"

#include "RenderEngine.h"
#include "texture/TextureManager.h"
#include "game/entity/Player.h"

void BlockRenderer::render(World &world)
{
    renderBlocks(world);
    renderClouds(world);
}

BlockRenderer::BlockRenderer(RenderEngine &e) : BaseRenderer(e)
{

}

void BlockRenderer::renderBlocks(World &world)
{
    auto const &blocks = world.getBlocks();

    ClearBackground(SKYBLUE);
    for (auto const &block: blocks)
    {
        if (block.second == nullptr)
            continue;

        auto *texture = getRenderEngine().getTextureManager().getTexture(block.second->getTexture());

        DrawCubeTexture(*texture,
                        Vector3{(float) block.first.x, (float) block.first.y, (float) block.first.z}, 1.0f, 1.0f,
                        1.0f, WHITE);
    }
}

void BlockRenderer::renderClouds(World &world)
{
    DrawCube({-20, 40, -40}, 20, 3, 10, WHITE);
    DrawCube({30, 45, 15}, -40, 3, -40, WHITE);
    DrawCube({0, 40, -30}, 15, 3, 15, WHITE);
    DrawCube({10, 35, -5}, 10, 3, 25, WHITE);
    DrawCube({-5, 45, 40}, 25, 3, 20, WHITE);
    DrawCube({-25, 45, 10}, 25, 3, 20, WHITE);
}
