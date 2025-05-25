#pragma once

class PlayerBar : public GameObject 
{
private:
	const float SPEED = 500.0f;

public:
	PlayerBar();
	~PlayerBar();

	void Update();
	void Render();

private:
	void ControlKeyboard();
	void MakeMesh() override;
};