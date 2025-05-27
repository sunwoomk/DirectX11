#include "Framework.h"

BounceBall::BounceBall(PlayerBar* bar) : playerBar(bar)
{
    localPosition = CENTER;
    Init();
    Reset();
    circleCollider = new CircleCollider(5);
    playerCollider = playerBar->GetRectCollider();
}

BounceBall::~BounceBall()
{
    delete circleCollider;
    delete playerCollider;
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
            velocity = Vector2(0, SPEED);
        }
    }
    else 
    {
        localPosition += velocity * DELTA;
    }

    if (localPosition.x > SCREEN_WIDTH - radius || localPosition.x < radius) 
    {
        BounceX();
    }

    if (localPosition.y > SCREEN_HEIGHT - radius)
    {
        BounceY();
    }

    if (localPosition.y < radius)
        Reset();

    UpdateWorld();
    circleCollider->SetLocalPosition(localPosition);
    circleCollider->UpdateWorld();
    isCollide = circleCollider->IsRectCollision(playerCollider, overlap);

    if (isCollide) 
    {
        bounceDir = circleCollider->GetGlobalPosition() - playerCollider->GetGlobalPosition();
        bounceDir.Normalize();
        velocity = bounceDir * SPEED;
    }

}

void BounceBall::Render()
{
    GameObject::Render();
    circleCollider->Render();
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
