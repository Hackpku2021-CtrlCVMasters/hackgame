//
// Created by listerily on 5/8/21.
//

#include "GameClient.h"

#include "world/World.h"
#include "world/WorldGenerator.h"

#include "entity/Player.h"

#include "MainApplication.h"
#include "MouseListener.h"
#include "KeyEventListener.h"

#include <cmath>
#include <raylib.h>

GameClient::GameClient(MainApplication & app)
{
    application = &app;
    world = nullptr;
}

GameClient::~GameClient()
{
    delete world;
}

void GameClient::initialize()
{
    world = new World(*this);
    WorldGenerator generator(*world, *this);
    generator.generate();

    world->getPlayer()->move({10, 10, 10});

//    application->getMouseListener().disableCursor();
}

void GameClient::tick()
{
    handleMouseEvent();
    handleKeyboardEvent();

    world->tick();
}

World &GameClient::getWorld()
{
    return *world;
}

void GameClient::handleMouseEvent()
{
    static const float sensitivity = 0.003;

    auto* player = world->getPlayer();
    auto& mouseListener = application->getMouseListener();


    player->moveYaw(sensitivity * (float)mouseListener.getMouseOffsetX());
    player->movePitch(sensitivity * -(float)mouseListener.getMouseOffsetY());

    if(player->getPitch() > M_PI)
        player->setPitch(M_PI);
    if(player->getPitch() < -M_PI)
        player->setPitch(M_PI);
}

void GameClient::handleKeyboardEvent()
{
    auto& keyboardListener = application->getKeyEventListener();
    auto* player = world->getPlayer();
    if(keyboardListener.isKeyDown(KEY_SPACE))
    {
        player->move({0, 0.1, 0});
    }
    if(keyboardListener.isKeyDown(KEY_LEFT_SHIFT))
    {
        player->move({0, -0.1, 0});
    }
    if(keyboardListener.isKeyDown(KEY_W))
    {
        player->move({std::cos(player->getYaw()) * 0.1f, 0, std::sin(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_S))
    {
        player->move({-std::cos(player->getYaw()) * 0.1f, 0, -std::sin(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_D))
    {
        player->move({-std::sin(player->getYaw()) * 0.1f, 0, std::cos(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_A))
    {
        player->move({std::sin(player->getYaw()) * 0.1f, 0, -std::cos(player->getYaw()) * 0.1f});
    }
}

