//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_GAMECLIENT_H
#define PKU_GAME_CORE_GAMECLIENT_H

class MainApplication;
class GameClient
{
private:
    MainApplication* application;
public:
    explicit GameClient(MainApplication&);
    ~GameClient();

    void initialize();
    void tick();
};


#endif //PKU_GAME_CORE_GAMECLIENT_H
