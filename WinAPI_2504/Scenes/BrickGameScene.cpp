#include "Framework.h"
#include "BrickGameScene.h"

BrickGameScene::BrickGameScene()
{
	playerBar = new PlayerBar();
	bounceBall = new BounceBall(playerBar);
}

BrickGameScene::~BrickGameScene()
{
	delete playerBar;
	delete bounceBall;
}

void BrickGameScene::Update()
{
	playerBar->Update();
	bounceBall->Update();
}

void BrickGameScene::Render()
{
	playerBar->Render();
	bounceBall->Render();
}
