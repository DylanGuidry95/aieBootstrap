#pragma once
#include "Player.h"
#include "Wumpus.h"
#include "Encounter.h"
#include "Tile.h"

class Dungeon
{
private:
	int width = 2, height = 2;
	Tile *floorPlan = new Tile[width * height];
	Player *player;
	Wumpus *wumpus;
	
public:
	void SetPlayer(Player* p)
	{
		player = p;
	}

	void SetWumpus(Wumpus* w)
	{
		wumpus = w;
	}

	void Create(int w, int h)
	{
		width = w;
		height = h;
		delete[] floorPlan;
		floorPlan = new Tile[width * height];
		Tile *first = &floorPlan[0];
		int createdFloors = 0;
		int x = 0, y = 0;
		int targetTiles = width * height;
		while (createdFloors < targetTiles)
		{
			x = (createdFloors % width == 0) ? 0 :  x + 1;
			y = (createdFloors % width == 0 && createdFloors != 0) ? y + 1 : y;			
			*first++ = Tile(Vector2::Create(x,(height - 1 - y)));
			createdFloors++;
		}
	}

	void Update()
	{
		BoundsCheck();
	}

	void BoundsCheck()
	{
		if (player->GetPosition().xPos < 0 || player->GetPosition().xPos >= width || player->GetPosition().yPos < 0 || player->GetPosition().yPos >= height)
		{
			player->SetDirection(Direction(player->GetDirection() * (Direction)-1));
		}

		if (wumpus->GetPosition().xPos < 0 || wumpus->GetPosition().xPos >= width || wumpus->GetPosition().yPos < 0 || wumpus->GetPosition().yPos >= height)
		{
			wumpus->SetDirection(Direction(wumpus->GetDirection() * (Direction)-1));
		}
	}

	void Draw(aie::Renderer2D* renderer)
	{
		Tile *first = &floorPlan[0];
		int roomsDrawn = 1;
		while (roomsDrawn <= width * height)
		{						
			first++->Draw(renderer);			
			roomsDrawn++;
		}
	}
};