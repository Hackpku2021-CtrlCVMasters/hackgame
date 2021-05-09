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

    world->getPlayer()->move({1, 50, 1});
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
    static const float sensitivity = 0.005;

    auto* player = world->getPlayer();
    auto& mouseListener = application->getMouseListener();

    player->moveYaw(sensitivity * (float)mouseListener.getMouseOffsetX());
    player->movePitch(sensitivity * (float)-mouseListener.getMouseOffsetY());

    if(player->getPitch() > M_PI / 2 - 0.1)
        player->setPitch(M_PI / 2 -0.1);
    if(player->getPitch() < -M_PI / 2 + 0.1)
        player->setPitch(-M_PI / 2 + 0.1);
}

void GameClient::handleKeyboardEvent()
{
    auto& keyboardListener = application->getKeyEventListener();
    auto* player = world->getPlayer();
    if(keyboardListener.isKeyDown(KEY_SPACE))
    {
        if(player->canJump())
            player->jump();
    }
//    if(keyboardListener.isKeyDown(KEY_LEFT_SHIFT))
//    {
//        player->setControlledSpeed({0, -0.1, 0});
//    }
    if(keyboardListener.isKeyDown(KEY_W))
    {
        player->setControlledSpeed({std::cos(player->getYaw()) * 0.1f, 0, std::sin(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_S))
    {
        player->setControlledSpeed({-std::cos(player->getYaw()) * 0.1f, 0, -std::sin(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_D))
    {
        player->setControlledSpeed({-std::sin(player->getYaw()) * 0.1f, 0, std::cos(player->getYaw()) * 0.1f});
    }
    if(keyboardListener.isKeyDown(KEY_A))
    {
        player->setControlledSpeed({std::sin(player->getYaw()) * 0.1f, 0, -std::cos(player->getYaw()) * 0.1f});
    }
}

