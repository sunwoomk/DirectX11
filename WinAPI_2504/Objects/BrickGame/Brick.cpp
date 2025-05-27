#include "Framework.h"

Brick::Brick(BounceBall* bounceBall) : bounceBall(bounceBall)
{
	localPosition = CENTER;
	Init();
	rectCollider = new RectCollider(Vector2(sizeX, sizeY));
	rectCollider->SetLocalPosition(localPosition);
	bounceBallColider = bounceBall->GetCircleCollider();
}

Brick::~Brick()
{
	delete rectCollider;
	delete bounceBallColider;
}

void Brick::Update()
{
	if (!this->IsActive() || !rectCollider->IsActive()) return;

	UpdateWorld();
	rectCollider->UpdateWorld();

	rectCollider->SetLocalPosition(this->localPosition);

	isCollide = rectCollider->IsCircleCollision(bounceBallColider);

	if (isCollide)
	{
		this->SetActive(false);
		rectCollider->SetActive(false);
		if (bounceBall->GetGlobalPosition().x > this->GetGlobalPosition().x + sizeX / 2 
			|| bounceBall->GetGlobalPosition().x < this->GetGlobalPosition().x - sizeX / 2)
		{
			bounceBall->BounceX();
		}
		else 
		{
			bounceBall->BounceY();
		}
	}
}

void Brick::Render()
{
	GameObject::Render();
	rectCollider->Render();
}

void Brick::MakeMesh()
{
	int halfSizeX = sizeX / 2;
	int halfSizeY = sizeY / 2;
	vertices.emplace_back(-halfSizeX, halfSizeY, 1, 0, 0);
	vertices.emplace_back(halfSizeX, halfSizeY, 1, 0, 0);
	vertices.emplace_back(halfSizeX, -halfSizeY, 1, 0, 0);
	vertices.emplace_back(-halfSizeX, -halfSizeY, 1, 0, 0);

	indices = { 0, 1, 2, 0, 2, 3 };
}
