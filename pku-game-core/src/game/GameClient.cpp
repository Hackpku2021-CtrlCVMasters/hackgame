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
    paused = false;
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
}

void GameClient::tick()
{
    handleMouseEvent();
    handleKeyboardEvent();

    if(!paused)
        world->tick();

    if(world->getPlayer()->getHealth() <= 0)
        setGamePaused(true);
    if(world->getPlayer()->getScore() >= world->getTargetScore())
        setGamePaused(true);
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
    static const float movingSpeed = 0.15f;
    auto& keyboardListener = application->getKeyEventListener();
    auto* player = world->getPlayer();
    if(keyboardListener.isKeyDown(KEY_SPACE))
    {
        if(player->canJump())
            player->jump();
    }
    if(keyboardListener.isKeyDown(KEY_W))
    {
        player->setControlledSpeed({std::cos(player->getYaw()) * movingSpeed, 0, std::sin(player->getYaw()) * movingSpeed});
    }
    if(keyboardListener.isKeyDown(KEY_S))
    {
        player->setControlledSpeed({-std::cos(player->getYaw()) * movingSpeed, 0, -std::sin(player->getYaw()) * movingSpeed});
    }
    if(keyboardListener.isKeyDown(KEY_D))
    {
        player->setControlledSpeed({-std::sin(player->getYaw()) * movingSpeed, 0, std::cos(player->getYaw()) * movingSpeed});
    }
    if(keyboardListener.isKeyDown(KEY_A))
    {
        player->setControlledSpeed({std::sin(player->getYaw()) * movingSpeed, 0, -std::cos(player->getYaw()) * movingSpeed});
    }
}

bool GameClient::isGamePaused() const
{
    return paused;
}

void GameClient::setGamePaused(bool p)
{
    paused = p;
}

