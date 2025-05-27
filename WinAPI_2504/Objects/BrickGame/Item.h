#pragma once

class Item : public GameObject 
{
private:
	const float SPEED = 100.0f;
public:
	Item();
	~Item();

	void Update();
	void Render();

private:
	void MakeMesh() override;

private:
	RectCollider* rectCollider;
};
