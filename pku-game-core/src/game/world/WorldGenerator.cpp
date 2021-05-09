//
// Created by listerily on 5/9/21.
//

#include "WorldGenerator.h"

#include "World.h"

#include "../block/Block.h"
#include "../entity/Player.h"

#include <json/json.h>
#include <fstream>
#include <memory>
#include <game/entity/Slime.h>

WorldGenerator::WorldGenerator(World &world, GameClient &client) :
        world(&world), gameClient(&client)
{

}

WorldGenerator::~WorldGenerator()
{

}

void WorldGenerator::generate()
{
    using namespace Json;
    using namespace std;

    Value value;
    std::ifstream("../config/world_data.json") >> value;
    for(auto const& v: value["blocks"])
    {
        int x = v["pos"][0].asInt();
        int y = v["pos"][1].asInt();
        int z = v["pos"][2].asInt();

        world->setBlock(x, y, z, std::move(std::make_unique<Block>(v["id"].asString(), v["texture"].asString())));
    }

    for(auto const& v: value["entities"])
    {
        float x = v["pos"][0].asFloat();
        float y = v["pos"][1].asFloat();
        float z = v["pos"][2].asFloat();

        if(v["id"].asString() == "slime")
        {
            auto slime = std::make_unique<Slime>(*world);
            slime->setPos(Vec3f{x, y, z});
            world->addEntity(std::move(slime));
        }
    }

    auto player = std::make_unique<Player>(*world);
    player->setPos({0, 10.0f, 0});
    for(int i = 50; i >= 0; --i)
    {
        if(world->getBlockAt(0, i, 0))
        {
            player->setPos({0, (float)i + 1.0f, 0});
            break;
        }
    }
    world->addPlayer(std::move(player));

}
