#include "Framework.h"
#include "PlayerBar.h"
#include "BounceBall.h"

BounceBall::BounceBall(PlayerBar* bar) : playerBar(bar)
{
    localPosition = CENTER;
    Init();
    Reset();
}

BounceBall::~BounceBall()
{
}

void BounceBall::Update()
{
    if (!isLaunched) 
    {
        Vector2 barPos = playerBar->GetLocalPosition();
        localPosition.x = barPos.x;
        localPosition.y = barPos.y - 335;

        if (Input::Get()->IsKeyDown(VK_SPACE)) 
        {
            isLaunched = true;
            velocity = Vector2(400, 400);
        }
    }
    else 
    {
        localPosition += velocity * DELTA;
    }

    if (localPosition.x > SCREEN_WIDTH - radius || localPosition.x < radius) 
    {
        velocity.x = -velocity.x;
    }

    if (localPosition.y > SCREEN_HEIGHT - radius || localPosition.y < radius)
    {
        velocity.y = -velocity.y;
    }

    UpdateWorld();
}

void BounceBall::Render()
{
    GameObject::Render();
}

void BounceBall::Reset()
{
    isLaunched = false;
    velocity = Vector2(0, 0);
}

void BounceBall::MakeMesh()
{
    int segments = 20;
    float angleStep = XM_2PI / segments;
    vertices.clear();

    vertices.emplace_back(0, 0, 1, 1, 1);

    for (int i = 0; i <= segments; ++i) 
    {
        float angle = i * angleStep;
        float x = cos(angle) * radius;
        float y = sin(angle) * radius;
        vertices.emplace_back(x, y, 1, 1, 1);
    }

    indices.clear();
    for (int i = 1; i <= segments; ++i) 
    {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i);
    }
}
