//
// Created by listerily on 5/8/21.
//

#include <complex>
#include "EntityRenderer.h"

#include "game/entity/Entity.h"
#include "game/world/World.h"
#include "game/entity/Slime.h"

#include "raylib.h"

EntityRenderer::EntityRenderer(RenderEngine &engine) : BaseRenderer(engine)
{

}

void EntityRenderer::render(World &world)
{
    auto const &entities = world.getEntities();

    for (const auto &entity : entities)
    {
        if (entity->getTypeId() == Slime::TYPE_ID)
        {
            auto *slime = dynamic_cast<Slime *>(entity.get());

            //Draw body
            {
                float x = slime->getPosition().x;
                float y = slime->getPosition().y;
                float z = slime->getPosition().z;
                float size = slime->getSize();
                float height = slime->getHeight();

                float p1x = size * std::cos(slime->getFacing());
                float p1z = size * std::sin(slime->getFacing());
                float p2x = size * -std::sin(slime->getFacing());
                float p2z = size * std::cos(slime->getFacing());
                float p3x = size * -std::cos(slime->getFacing());
                float p3z = size * -std::sin(slime->getFacing());
                float p4x = size * std::sin(slime->getFacing());
                float p4z = size * -std::cos(slime->getFacing());

                auto slimeColor = (Color){ 0, 120, 0, 192 };

                DrawTriangle3D({x + p1x, y, z + p1z}, {x + p2x, y, z + p2z}, {x + p3x, y, z + p3z}, slimeColor);
                DrawTriangle3D({x + p1x, y, z + p1z}, {x + p3x, y, z + p3z}, {x + p4x, y, z + p4z}, slimeColor);
                DrawTriangle3D({x + p3x, y + height, z + p3z}, {x + p2x, y + height, z + p2z},
                               {x + p1x, y + height, z + p1z}, slimeColor);
                DrawTriangle3D({x + p4x, y + height, z + p4z}, {x + p3x, y + height, z + p3z},
                               {x + p1x, y + height, z + p1z}, slimeColor);

                DrawTriangle3D({x + p2x, y + height, z + p2z}, {x + p2x, y, z + p2z}, {x + p1x, y, z + p1z}, slimeColor);
                DrawTriangle3D({x + p1x, y + height, z + p1z}, {x + p2x, y + height, z + p2z}, {x + p1x, y, z + p1z}, slimeColor);
                DrawTriangle3D({x + p4x, y + height, z + p4z}, {x + p4x, y, z + p4z}, {x + p3x, y, z + p3z}, slimeColor);
                DrawTriangle3D({x + p3x, y + height, z + p3z}, {x + p4x, y + height, z + p4z}, {x + p3x, y, z + p3z}, slimeColor);

                DrawTriangle3D({x + p3x, y, z + p3z}, {x + p2x, y, z + p2z}, {x + p2x, y + height, z + p2z}, slimeColor);
                DrawTriangle3D({x + p3x, y, z + p3z}, {x + p2x, y + height, z + p2z}, {x + p3x, y + height, z + p3z}, slimeColor);
                DrawTriangle3D({x + p4x, y + height, z + p4z}, {x + p1x, y, z + p1z}, {x + p4x, y, z + p4z}, slimeColor);
                DrawTriangle3D({x + p1x, y + height, z + p1z}, {x + p1x, y, z + p1z}, {x + p4x, y + height, z + p4z}, slimeColor);
            }

            //Draw eyes
            {
                float x = slime->getPosition().x;
                float y = slime->getPosition().y;
                float z = slime->getPosition().z;
                float size = slime->getSize() * 1.1f;
                float top = slime->getHeight() * 0.8f;
                float bottom = slime->getHeight() * 0.35f;

                //Draw left eye
                {
                    float p1x = size * std::cos(slime->getFacing());
                    float p1z = size * std::sin(slime->getFacing());
                    float p4x = size * std::sin(slime->getFacing());
                    float p4z = size * -std::cos(slime->getFacing());
                    float xOffset = p1x - p4x;
                    float zOffset = p1z - p4z;
                    p1x -= xOffset * 0.2f;
                    p4x += xOffset * 0.65f;
                    p1z -= zOffset * 0.2f;
                    p4z += zOffset * 0.65f;

                    DrawTriangle3D({x + p4x, y + top, z + p4z}, {x + p1x, y + bottom, z + p1z}, {x + p4x, y + bottom, z + p4z}, BLACK);
                    DrawTriangle3D({x + p1x, y + top, z + p1z}, {x + p1x, y + bottom, z + p1z}, {x + p4x, y + top, z + p4z}, BLACK);
                }
                //Draw right eye
                {
                    float p1x = size * std::cos(slime->getFacing());
                    float p1z = size * std::sin(slime->getFacing());
                    float p4x = size * std::sin(slime->getFacing());
                    float p4z = size * -std::cos(slime->getFacing());
                    float xOffset = p1x - p4x;
                    float zOffset = p1z - p4z;
                    p1x -= xOffset * 0.65f;
                    p4x += xOffset * 0.2f;
                    p1z -= zOffset * 0.65f;
                    p4z += zOffset * 0.2f;

                    DrawTriangle3D({x + p4x, y + top, z + p4z}, {x + p1x, y + bottom, z + p1z}, {x + p4x, y + bottom, z + p4z}, BLACK);
                    DrawTriangle3D({x + p1x, y + top, z + p1z}, {x + p1x, y + bottom, z + p1z}, {x + p4x, y + top, z + p4z}, BLACK);

                }
            }

        }
    }
}
