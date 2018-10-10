#pragma once
#include "Player.h"
#include "Encounter.h"
#include "input.h"

class PlayerController
{
private:
	Player* mPlayer;
	Direction GetDirection()
	{
		aie::Input* input = aie::Input::getInstance();
		if (input->wasKeyPressed(aie::INPUT_KEY_W))
			return Direction::NORTH;
		if (input->wasKeyPressed(aie::INPUT_KEY_S))
			return Direction::SOUTH;
		if (input->wasKeyPressed(aie::INPUT_KEY_D))
			return Direction::EAST;
		if (input->wasKeyPressed(aie::INPUT_KEY_A))
			return Direction::WEST;
	}

public:
	PlayerController()
	{
		mPlayer = new Player();
	}

	PlayerController(Player* player)
	{
		mPlayer = player;
	}

	void Update()
	{		
		Direction dir;				
		dir = GetDirection();		
		mPlayer->SetDirection(dir);		
	}

	void ActionSelection(Encounter encounter)
	{
		if (encounter.encounter == nullptr)
			return;
		std::cout << "You encountered a " << encounter.encounter->GetName() << std::endl;
		std::cout << "What are you gonna do?\n";
		switch (encounter.encounterType)
		{
		case Encounters::enemy:
		{
			std::cout << "1. Attack\n2.Flee\n";
			char action = ' ';
			std::cin >> action;
			if (action % 49 == 0)
			{
				encounter.encounter->Encounter(mPlayer);
				mPlayer->Encounter(encounter.encounter);				
				return;
			}
			mPlayer->SetDirection(Direction(mPlayer->GetDirection() * -1));
			mPlayer->Move();
		}
			break;
		case Encounters::item:
			break;
		default:
			break;
		}
	}

	Player* GetPlayer()
	{
		return mPlayer;
	}
};