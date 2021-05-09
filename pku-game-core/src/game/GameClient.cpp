//
// Created by listerily on 5/8/21.
//

#include "GameClient.h"

#include "world/World.h"
#include "world/WorldGenerator.h"

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
}

void GameClient::tick()
{
    world->tick();
}

World &GameClient::getWorld()
{
    return *world;
}