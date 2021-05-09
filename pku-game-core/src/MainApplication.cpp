#include <raylib.h>

#include "MainApplication.h"
#include "game/GameClient.h"
#include "renderer/RenderEngine.h"
#include "MouseListener.h"
#include "KeyEventListener.h"

#include <thread>

MainApplication::MainApplication()
{
    screenHeight = 720;
    screenWidth = 1080;
    windowName = "Demo Hack pku game";
    gameClient = new GameClient(*this);
    renderEngine = new RenderEngine(*this);
    keyEventListener = new KeyEventListener(*this);
    mouseListener = new MouseListener(*this);
}

MainApplication::~MainApplication()
{
    delete gameClient;
    delete renderEngine;
    delete keyEventListener;
    delete mouseListener;
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
            logicMutex.lock();
            logicTick();
            logicMutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }).detach();

    //start render loop
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        logicMutex.lock();
        renderTick();
        logicMutex.unlock();
    }

    CloseWindow();
}

void MainApplication::renderTick()
{
    renderEngine->render();
}

void MainApplication::logicTick()
{
    gameClient->tick();
}

GameClient &MainApplication::getGameClient()
{
    return *gameClient;
}

RenderEngine &MainApplication::getRenderEngine()
{
    return *renderEngine;
}
