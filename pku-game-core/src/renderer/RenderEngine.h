//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_RENDERENGINE_H
#define PKU_GAME_CORE_RENDERENGINE_H

class MainApplication;
class RenderEngine
{
private:
    MainApplication* app;
public:
    explicit RenderEngine(MainApplication&);
    ~RenderEngine();

    void initialize();
    void tick();
};


#endif //PKU_GAME_CORE_RENDERENGINE_H
