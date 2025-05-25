#pragma once

class PlayerBar;

class BounceBall : public GameObject
{
public:
    BounceBall(PlayerBar* bar);
    ~BounceBall();

    void Update();
    void Render();

    void Reset();

private:
    void MakeMesh() override;

    float radius = 5;
    bool isLaunched = false;
    Vector2 velocity;

    PlayerBar* playerBar;
};
