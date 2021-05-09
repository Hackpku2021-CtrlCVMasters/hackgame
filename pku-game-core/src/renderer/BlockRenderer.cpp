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

#include <cmath>

#include <fmt/format.h>

void BlockRenderer::render(World &world)
{
    auto const& blocks = world.getBlocks();

    ClearBackground(RAYWHITE);

    for(auto const& block: blocks)
    {
        if(block.second == nullptr)
            continue;

        auto* texture = getRenderEngine().getTextureManager().getTexture(block.second->getTexture());
        DrawCubeTexture(*texture,
                        Vector3{(float)block.first.x, (float)block.first.y, (float)block.first.z}, 1.0f, 1.0f, 1.0f, WHITE);
    }

    DrawGrid(10, 1.0f);


}

BlockRenderer::BlockRenderer(RenderEngine & e) : BaseRenderer(e){

}
