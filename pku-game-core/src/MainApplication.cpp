#include <raylib.h>

#include "MainApplication.h"
#include "game/GameClient.h"
#include "renderer/RenderEngine.h"

#include <thread>

MainApplication::MainApplication()
{
    screenHeight = 720;
    screenWidth = 1080;
    windowName = "Demo Hack pku game";
    gameClient = new GameClient(*this);
    renderEngine = new RenderEngine(*this);
}

MainApplication::~MainApplication()
{
    delete gameClient;
    delete renderEngine;
}

void MainApplication::main()
{
    InitWindow(screenWidth, screenHeight, windowName.c_str());
    gameClient->initialize();
    renderEngine->initialize();

    //start logic loop
    std::thread([this](){
        while(!WindowShouldClose())
        {
            gameClient->tick();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }).detach();

    //start render loop
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        renderTick();
    }

    CloseWindow();
}

void MainApplication::renderTick()
{
    renderEngine->tick();
}

void MainApplication::logicTick()
{
    gameClient->tick();
}
