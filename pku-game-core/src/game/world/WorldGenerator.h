//
// Created by listerily on 5/9/21.
//

#ifndef PKU_GAME_CORE_WORLDGENERATOR_H
#define PKU_GAME_CORE_WORLDGENERATOR_H


class World;
class GameClient;
class WorldGenerator
{
private:
    World* world;
    GameClient* gameClient;
public:
    WorldGenerator(World& world, GameClient&);
    ~WorldGenerator();

    void generate();
};


#endif //PKU_GAME_CORE_WORLDGENERATOR_H
