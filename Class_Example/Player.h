#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();	
	Player(Math::Vector2D pos, float movementSpeed = 0, float rotation = 0,
		aie::Texture *texture = new aie::Texture("./textures/ball.png"));
	virtual void Start() override;
	virtual void Update(float dt) override;
};