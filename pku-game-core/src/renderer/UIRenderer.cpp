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
        DrawRectangle( 50, 50, app.getScreenWidth() - 100, app.getScreenHeight() - 100, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 50, 50, app.getScreenWidth() - 100, app.getScreenHeight() - 100, BLUE);

        if(world.getPlayer()->getScore() >= world.getTargetScore())
        {
            static const char* title = "!!YOU WON!!";
            int titleWidth = MeasureText(title, 150);
            DrawText(title, app.getScreenWidth() / 2 - titleWidth / 2,
                     (int)(app.getScreenHeight() * 0.2) + 50, 150, GOLD);

            static const char* congratulations = "congratulations";
            int congratulationsWidth = MeasureText(congratulations, 30);
            DrawText(congratulations, app.getScreenWidth() / 2 - congratulationsWidth / 2,
                     (int)(app.getScreenHeight() * 0.6) + 50, 30, BLACK);
        }
        if(world.getPlayer()->getHealth() <= 0)
        {
            static const char* title = "!!YOU FAILED!!";
            int titleWidth = MeasureText(title, 150);
            DrawText(title, app.getScreenWidth() / 2 - titleWidth / 2,
                     (int)(app.getScreenHeight() * 0.2) + 50, 150, RED);

            static const char* tryAgain = "try again?";
            int tryAgainWidth = MeasureText(tryAgain, 30);
            DrawText(tryAgain, app.getScreenWidth() / 2 - tryAgainWidth / 2,
                     (int)(app.getScreenHeight() * 0.6) + 50, 30, BLACK);
        }

    }
}
