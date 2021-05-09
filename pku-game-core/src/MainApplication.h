#ifndef PKU_GAME_CORE_MAINAPPLICATION_H
#define PKU_GAME_CORE_MAINAPPLICATION_H

#include <string>
#include <mutex>

class GameClient;
class RenderEngine;
class KeyEventListener;
class MouseListener;
class MainApplication
{
private:
    GameClient* gameClient;
    RenderEngine* renderEngine;
    KeyEventListener* keyEventListener;
    MouseListener* mouseListener;
    int screenWidth;
    int screenHeight;
    std::string windowName;
    std::mutex logicMutex;
public:
    MainApplication();
    ~MainApplication();

    void main();
    GameClient& getGameClient();
    RenderEngine& getRenderEngine();
private:
    void renderTick();
    void logicTick();
};


#endif //PKU_GAME_CORE_MAINAPPLICATION_H
