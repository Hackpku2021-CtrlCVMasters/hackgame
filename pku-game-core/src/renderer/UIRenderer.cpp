//
// Created by listerily on 5/8/21.
//

#include "UIRenderer.h"

#include <raylib.h>
#include <sstream>

#include "game/world/World.h"
#include "game/entity/Player.h"

UIRenderer::UIRenderer(RenderEngine &engine) : BaseRenderer(engine){

}

void UIRenderer::render(World &world)
{
    std::stringstream health;
    health << "Health point: " << world.getPlayer()->getHealth() << ".";

    std::stringstream score;
    score << "Score: " << world.getPlayer()->getScore() << " / " << world.getTargetScore() << ".";

    DrawText("[Slime Escape]", 20, 20, 20, BLACK);
    DrawText(health.str().c_str(), 20, 50, 20, MAROON);
    DrawText(score.str().c_str(), 20, 80, 20, GOLD);
}
