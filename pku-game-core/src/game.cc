#include "game.h"
#include <boost/asio.hpp>

int main()
{
    Game *g = new Game();
    InitWindow(g->screenWidth, g->screenHeight, "sample game: snake");
    g->InitGame();

    SetTargetFPS(60);

    //Main game loop
    //Detect window close button or ESC key
    while (!WindowShouldClose())
    {
        g->UpdateGame();
        g->DrawGame();
    }


    //Close window and OpenGL context
    CloseWindow();

    return 0;
}
