#include "Framework.h"

PlayerBar::PlayerBar()
{
	localPosition = CENTER;
	Init();
    rectCollider = new RectCollider(Vector2(120, 20));
}

PlayerBar::~PlayerBar()
{
    delete rectCollider;
}

void PlayerBar::Update()
{
	ControlKeyboard();
	UpdateWorld();
    rectCollider->SetLocalPosition(localPosition - Vector2(0, 350));
    rectCollider->UpdateWorld();
}

void PlayerBar::Render()
{
	GameObject::Render();
    rectCollider->Render();
}

void PlayerBar::ControlKeyboard()
{
	if (Input::Get()->IsKeyPress('D') && this->GetLocalPosition().x < SCREEN_WIDTH - 60)
	{
		Translate(Vector2::Right() * SPEED * DELTA);
	}

	if (Input::Get()->IsKeyPress('A') && this->GetLocalPosition().x > 60)
	{
		Translate(Vector2::Left() * SPEED * DELTA);
	}
}

void PlayerBar::MakeMesh() {

    vertices.emplace_back(-60, -360, 1, 0, 0);
    vertices.emplace_back(-60, -340, 1, 0, 0);
    vertices.emplace_back(-50, -340, 1, 0, 0);
    vertices.emplace_back(-50, -360, 1, 0, 0);

    vertices.emplace_back(50, -360, 1, 0, 0);
    vertices.emplace_back(50, -340, 1, 0, 0);
    vertices.emplace_back(60, -340, 1, 0, 0);
    vertices.emplace_back(60, -360, 1, 0, 0);

    vertices.emplace_back(-50, -360, 0.5, 0.5, 0.5);
    vertices.emplace_back(-50, -340, 0.5, 0.5, 0.5);
    vertices.emplace_back(50, -340, 0.5, 0.5, 0.5);
    vertices.emplace_back(50, -360, 0.5, 0.5, 0.5);

    indices = {
        0,1,2, 0,2,3,
        4,5,6, 4,6,7,
        8,9,10, 8,10,11
    };
}
