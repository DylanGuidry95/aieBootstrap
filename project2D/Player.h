#pragma once
#include <iostream>
#include "Entity.h"

struct Player : public Entity
{
public:
	Player() : Entity()
	{
		mName = (char*)"Bobby";
		mTexture = new aie::Texture("./textures/ruby.png");
	}

	Player(Vector2 pos, const char* name) : Entity(pos)
	{
		mName = (char*)name;
		mTexture = new aie::Texture("./textures/ruby.png");
	}

	void Move() override
	{
		switch (mMovementDirection)
		{
		case NORTH:
			mPosition = mPosition + Vector2::Create(0, 1);
			break;
		case SOUTH:
			mPosition = mPosition + Vector2::Create(0, -1);
			break;
		case EAST:
			mPosition = mPosition + Vector2::Create(1, 0);
			break;
		case WEST:
			mPosition = mPosition + Vector2::Create(-1, 0);
			break;
		default:
			break;
		}
	}

	void Encounter(Entity* entity) override
	{
		entity->TakeDamage(mPower);
		SetDirection(Direction(mMovementDirection * -1));
	}

	void TakeDamage(int amount) override
	{
		mHealth -= amount;
	}
};