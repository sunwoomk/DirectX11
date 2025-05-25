#pragma once

class BrickGameScene : public Scene
{
public:
	BrickGameScene();
	~BrickGameScene();

	void Update() override;
	void Render() override;

private:
	PlayerBar* playerBar;
	BounceBall* bounceBall;
};