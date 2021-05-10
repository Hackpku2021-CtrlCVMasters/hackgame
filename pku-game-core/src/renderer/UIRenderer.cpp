//
// Created by listerily on 5/8/21.
//

#include "UIRenderer.h"

#include <raylib.h>
#include <sstream>

#include "game/world/World.h"
#include "game/entity/Player.h"
#include "game/GameClient.h"
#include "MainApplication.h"

UIRenderer::UIRenderer(RenderEngine &engine) : BaseRenderer(engine)
{

}

void UIRenderer::render(World &world, GameClient &client, MainApplication &app)
{
    std::stringstream title;
    title << "[" << app.getWindowName() << "]";

    std::stringstream health;
    health << "Health point: " << world.getPlayer()->getHealth() << ".";

    std::stringstream score;
    score << "Score: " << world.getPlayer()->getScore() << " / " << world.getTargetScore() << ".";

    if (!client.isGamePaused())
    {
        DrawText(title.str().c_str(), 20, 20, 20, BLACK);
        DrawText(health.str().c_str(), 20, 50, 20, MAROON);
        DrawText(score.str().c_str(), 20, 80, 20, GOLD);
    }
    else
    {
        ClearBackground(WHITE);
        DrawRectangle( 50, 50, app.getScreenWidth() - 100, app.getScreenHeight() - 100, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 50, 50, app.getScreenWidth() - 100, app.getScreenHeight() - 100, BLUE);

        if(world.getPlayer()->getScore() >= world.getTargetScore())
        {
            static const char* title = "!!YOU WON!!";
            int titleWidth = MeasureText(title, 60);
            DrawText(title, app.getScreenWidth() / 2 - titleWidth / 2, 90, 60, GOLD);

            static const char* restart = "Press [R] to restart.";
            int restartWidth = MeasureText(restart, 30);
            DrawText(restart, app.getScreenWidth() / 2 - restartWidth / 2, 200, 30, GRAY);
        }
    }
}
