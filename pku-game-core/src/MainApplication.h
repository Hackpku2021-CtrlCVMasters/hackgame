#ifndef PKU_GAME_CORE_MAINAPPLICATION_H
#define PKU_GAME_CORE_MAINAPPLICATION_H

#include <string>
#include <mutex>

class GameClient;
class RenderEngine;
class MainApplication
{
private:
    GameClient* gameClient;
    RenderEngine* renderEngine;
    int screenWidth;
    int screenHeight;
    std::string windowName;
    std::mutex logicMutex;
public:
    MainApplication();
    ~MainApplication();

    void main();
private:
    void renderTick();
    void logicTick();
};


#endif //PKU_GAME_CORE_MAINAPPLICATION_H
