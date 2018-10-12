#pragma once
#include "Wumpus.h"
#include "Encounter.h"
#include "input.h"

class WumpusController
{
private:
	Wumpus * mWumpus;
	float mActionDelay = 0;
	Direction GetDirection()
	{
		int a = ((rand() % 4) + 1);
		if (a == 1)
			return Direction::NORTH;
		if (a == 2)
			return Direction::SOUTH;
		if (a == 3)
			return Direction::EAST;
		if (a == 4)
			return Direction::WEST;
	}

public:
	WumpusController()
	{
		mWumpus = new Wumpus();
	}

	WumpusController(Wumpus* Wumpus)
	{
		mWumpus = Wumpus;
	}

	void Update(float dt)
	{
		mActionDelay += dt;
		if (mActionDelay >= 1)
		{
			Direction dir;
			dir = GetDirection();
			mWumpus->SetDirection(dir);
			mActionDelay = 0;
		}		
	}

	Wumpus* GetWumpus()
	{
		return mWumpus;
	}
};
