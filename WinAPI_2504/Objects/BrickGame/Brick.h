#pragma once

class Brick : public GameObject 
{
private:
	const float sizeX = 60;
	const float sizeY = 20;
public:
	Brick(BounceBall* bounceBall);
	~Brick();

	void Update();
	void Render();

	float GetSizeX() const { return sizeX; }
	float GetSizeY() const { return sizeY; }

private:
	void MakeMesh() override;

private:
	RectCollider* rectCollider;
	CircleCollider* bounceBallColider;
	BounceBall* bounceBall;
	bool isCollide = false;
};
