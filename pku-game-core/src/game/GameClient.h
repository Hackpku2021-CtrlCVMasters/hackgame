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
    bool paused;
public:
    explicit GameClient(MainApplication&);
    ~GameClient();

    void initialize();
    void tick();

    World& getWorld();

    bool isGamePaused() const;
    void setGamePaused(bool);

private:
    void handleMouseEvent();
    void handleKeyboardEvent();
};


#endif //PKU_GAME_CORE_GAMECLIENT_H
