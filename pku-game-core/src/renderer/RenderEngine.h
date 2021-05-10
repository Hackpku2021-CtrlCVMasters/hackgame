//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_RENDERENGINE_H
#define PKU_GAME_CORE_RENDERENGINE_H

class MainApplication;
class BlockRenderer;
class TextureManager;
class EntityRenderer;
class UIRenderer;
class RenderEngine
{
private:
    MainApplication* app;
    BlockRenderer* blockRenderer;
    TextureManager* textureManager;
    EntityRenderer* entityRenderer;
    UIRenderer* uiRenderer;
public:
    explicit RenderEngine(MainApplication&);
    ~RenderEngine();

    void initialize();
    void render();

    TextureManager& getTextureManager();
};


#endif //PKU_GAME_CORE_RENDERENGINE_H
