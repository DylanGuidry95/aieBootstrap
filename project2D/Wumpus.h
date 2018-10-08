#pragma once
#include <iostream>
#include "Entity.h"

class Wumpus : public Entity
{
private:
	int mMovementRange;
	Entity* mTarget;
public:
	Wumpus() : Entity()
	{
		mMovementRange = 1;
		mName = (char*)"Wumpus";
		mTexture = new aie::Texture("./textures/player.png");
	}

	Wumpus(Vector2 pos, int range) : Entity(pos)
	{
		mMovementRange = range;
		mName = (char*)"Wumpus";
		mTexture = new aie::Texture("./textures/player.png");
	}

	void Move() override
	{
		switch (mMovementDirection)
		{
		case NORTH:
			mPosition = mPosition + Vector2::Create(0, mMovementRange);
			break;
		case SOUTH:
			mPosition = mPosition + Vector2::Create(0, -mMovementRange);
			break;
		case EAST:
			mPosition = mPosition + Vector2::Create(mMovementRange, 0);
			break;
		case WEST:
			mPosition = mPosition + Vector2::Create(-mMovementRange, 0);
			break;
		default:
			break;
		}
	}

	void Encounter(Entity* entity) override
	{
		entity->TakeDamage(mPower);		
	}

	void TakeDamage(int amount) override
	{
		mHealth -= amount;
	}

	void SetTarget(Entity* target)
	{
		mTarget = target;
	}
};