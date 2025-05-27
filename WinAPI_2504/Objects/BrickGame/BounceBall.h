#pragma once

class PlayerBar;

class BounceBall : public GameObject
{
private:
    const float SPEED = 500.0f;
public:
    BounceBall(PlayerBar* bar);
    ~BounceBall();

    void Update();
    void Render();

    void Reset();

    CircleCollider* GetCircleCollider() { return circleCollider; }

    void BounceX() { velocity.x = -velocity.x; }
    void BounceY() { velocity.y = -velocity.y; }

private:
    void MakeMesh() override;

    float radius = 5;
    bool isLaunched = false;
    bool isCollide = false;
    Vector2 velocity;
    Vector2* overlap;
    Vector2 bounceDir;

    PlayerBar* playerBar;
    CircleCollider* circleCollider;
    RectCollider* playerCollider;
};
