#pragma once
#include "Player.h"
#include "Wumpus.h"
#include "Encounter.h"
#include "Tile.h"
#include "input.h"

class Dungeon
{
private:
	int width = 2, height = 2;
	LinkedList::UnorderedLinkedList<Tile> *mTiles;	
	Player *player;
	Wumpus *wumpus;
	
public:
	Dungeon()
	{
		Create(5, 5);
	}

	Dungeon(int width, int height)
	{
		Create(width, height);
	}

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
		mTiles = new LinkedList::UnorderedLinkedList<Tile>();
		width = w;
		height = h;			
		int createdFloors = 0;
		int x = 0, y = 0;
		int targetTiles = width * height;
		while (createdFloors < targetTiles)
		{
			x = (createdFloors % width == 0) ? 0 :  x + 1;
			y = (createdFloors % width == 0 && createdFloors != 0) ? y + 1 : y;			
			mTiles->InsertLast(Tile(Vector2::Create(x,(height - 1 - y))));
			createdFloors++;
		}
	}

	void Update()
	{		
		BoundsCheck();
		LinkedList::LinkedListIterator<Tile> tile = mTiles->Begin();
		while (tile != nullptr)
		{
			Tile curTile = *tile;
			if (curTile.GetPosition() == player->GetPosition())
			{
				aie::Input* input = aie::Input::getInstance();
				if (input->wasKeyPressed(aie::INPUT_KEY_P))
				{
					mTiles->DeleteNode(curTile);
					tile = mTiles->Begin();
					continue;
				}
			}
			++tile;
		}
	}

	void BoundsCheck()
	{
		LinkedList::LinkedListIterator<Tile> tile = mTiles->Begin();
		while (tile != nullptr)
		{
			Tile curTile = *tile;
			if (player->GetPosition() == curTile.GetPosition())
			{
				return;
			}
			if (wumpus->GetPosition() == curTile.GetPosition())
			{
				return;
			}
			++tile;
		}
		player->SetDirection(Direction(player->GetDirection() * (Direction)-1));
		wumpus->SetDirection(Direction(wumpus->GetDirection() * (Direction)-1));
	}

	void Draw(aie::Renderer2D* renderer)
	{
		LinkedList::LinkedListIterator<Tile> tile = mTiles->Begin();		
		while (tile != nullptr)
		{						
			Tile drawing = *tile;
			drawing.Draw(renderer);
			++tile;			
		}
	}
};