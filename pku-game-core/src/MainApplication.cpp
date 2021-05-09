#include <raylib.h>

#include "MainApplication.h"
#include "game/GameClient.h"
#include "renderer/RenderEngine.h"
#include "MouseListener.h"
#include "KeyEventListener.h"

MainApplication::MainApplication()
{
    screenHeight = 936;
    screenWidth = 1404;
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

    SetTargetFPS(20);

    gameClient->initialize();
    renderEngine->initialize();


    //start render loop
    while (!WindowShouldClose())
    {
        logicMutex.lock();
        logicTick();
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

KeyEventListener &MainApplication::getKeyEventListener()
{
    return *keyEventListener;
}

MouseListener &MainApplication::getMouseListener()
{
    return *mouseListener;
}
