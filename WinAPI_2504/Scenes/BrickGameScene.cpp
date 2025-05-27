#include "Framework.h"
#include "BrickGameScene.h"

BrickGameScene::BrickGameScene()
{
	playerBar = new PlayerBar();
	bounceBall = new BounceBall(playerBar);

	int rowCount = 5;
	int colCount = 10;
	float startX = 20; // ù ��� x��ǥ
	float startY = 770; // ù ��� y��ǥ
	float gapX = 10;    // ��� ���� x ����
	float gapY = 10;    // ��� ���� y ����

	for (int row = 0; row < rowCount; ++row)
	{
		for (int col = 0; col < colCount; ++col)
		{
			Brick* brick = new Brick(bounceBall);

			float x = startX + col * (brick->GetSizeX() + gapX);
			float y = startY - row * (brick->GetSizeY() + gapY);

			brick->SetLocalPosition(Vector2(x, y));
			bricks.push_back(brick);
		}
	}
}

BrickGameScene::~BrickGameScene()
{
	delete playerBar;
	delete bounceBall;
	for (auto& brick : bricks)
		delete brick;
	bricks.clear();
}

void BrickGameScene::Update()
{
	playerBar->Update();
	bounceBall->Update();
	for (auto& brick : bricks)
		brick->Update();
}

void BrickGameScene::Render()
{
	playerBar->Render();
	bounceBall->Render();
	for (auto& brick : bricks)
		brick->Render();
}
