#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
#include "Texture.h"

enum Direction
{
	NORTH = 1,
	SOUTH = -1,
	WEST = 2,
	EAST = -2
};

class Entity
{
protected:
	Vector2 mPosition;
	int mPower;
	int mHealth;
	char *mName;
	Direction mMovementDirection;
	aie::Texture *mTexture;

public:
	Entity()
	{
		mPosition = Vector2::Create(0,0);
		mHealth = 100;
		mPower = 10;
		mName = (char*)"";
		mMovementDirection = Direction::NORTH;
	}

	Entity(Vector2 pos)
	{
		mPosition = pos;
		mHealth = 100;
		mPower = 10;
		mName = (char*)"";
		mMovementDirection = Direction::NORTH;
	}

	virtual void Move() {};

	virtual void Encounter(Entity* entity) {};

	virtual void TakeDamage(int amount) {};

	void SetDirection(Direction dir)
	{
		if ((int)dir == 1 || (int)dir == -1 || (int)dir == 2 || (int)dir == -2)
		{
			mMovementDirection = dir;
			Move();
		}
	}

	Direction GetDirection()
	{
		return mMovementDirection;
	}

	Vector2 GetPosition()
	{
		return mPosition;
	}

	int GetHealth()
	{
		return mHealth;
	}

	char* GetName()
	{
		return mName;
	}

	void DisplayDebugInfo()
	{
		std::cout << "Name: " << mName << std::endl;
		std::cout << "Position: " << mPosition << std::endl;
	}

	void Draw(aie::Renderer2D* renderer)
	{		
		renderer->setUVRect(0, 0, 1, 1);
		switch (mMovementDirection)
		{
		case Direction::NORTH:
			renderer->drawSprite(mTexture, (mPosition.xPos * 51) + 25, (mPosition.yPos * 51) + 25, 50, 50, 3.14f);
			break;
		case Direction::SOUTH:
			renderer->drawSprite(mTexture, (mPosition.xPos * 51) + 25, (mPosition.yPos * 51) + 25, 50, 50, 0);
			break;
		case Direction::EAST:
			renderer->drawSprite(mTexture, (mPosition.xPos * 51) + 25, (mPosition.yPos * 51) + 25, 50, 50, 1.57f);
			break;
		case Direction::WEST:
			renderer->drawSprite(mTexture, (mPosition.xPos * 51) + 25, (mPosition.yPos * 51) + 25, 50, 50, -1.57f);
			break;
		default:
			break;
		}
	}

	bool operator==(const Entity& rhs)
	{
		return mName == rhs.mName && mPosition == mPosition && mHealth == mHealth;
	}
};