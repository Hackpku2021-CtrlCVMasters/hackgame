//
// Created by listerily on 5/8/21.
//

#include <raylib.h>
#include "BlockRenderer.h"

#include "game/world/World.h"
#include "game/block/Block.h"

void BlockRenderer::render(World &world)
{
    auto const& blocks = world.getBlocks();

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);
    UpdateCamera(&camera);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    for(auto const& block: blocks)
    {
        DrawCube(Vector3{block.first.x, block.first.y, block.first.z}, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(Vector3{block.first.x, block.first.y, block.first.z}, 2.0f, 2.0f, 2.0f, MAROON);
    }

    DrawGrid(10, 1.0f);

    EndMode3D();

    EndDrawing();
}
