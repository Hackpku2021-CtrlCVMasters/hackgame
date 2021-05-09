//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_GAMECLIENT_H
#define PKU_GAME_CORE_GAMECLIENT_H

class MainApplication;
class World;

class GameClient
{
private:
    MainApplication* application;
    World* world;
public:
    explicit GameClient(MainApplication&);
    ~GameClient();

    void initialize();
    void tick();

    World& getWorld();

private:
    void handleMouseEvent();
    void handleKeyboardEvent();
};


#endif //PKU_GAME_CORE_GAMECLIENT_H
