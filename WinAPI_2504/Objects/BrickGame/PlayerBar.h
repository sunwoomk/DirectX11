#pragma once

class PlayerBar : public GameObject 
{
private:
	const float SPEED = 700.0f;

public:
	PlayerBar();
	~PlayerBar();

	void Update();
	void Render();

	RectCollider* GetRectCollider() { return rectCollider; }

private:
	void ControlKeyboard();
	void MakeMesh() override;

private:
	RectCollider* rectCollider;
};