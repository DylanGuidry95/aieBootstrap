#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "UnorderedLinkedList.h"
class Tile
{
private:
	Vector2 position;
	aie::Texture *mTexture;	
	LinkedList::UnorderedLinkedList<Entity> *mEntityList;
public:
	Tile()
	{
		mTexture = new aie::Texture("./textures/tile.png");
		mEntityList = new LinkedList::UnorderedLinkedList<Entity>();
		position = Vector2::Create(0, 0);
	}

	Tile(Vector2 pos)
	{
		mTexture = new aie::Texture("./textures/tile.png");
		mEntityList = new LinkedList::UnorderedLinkedList<Entity>();
		position = pos;
	}	

	void Draw(aie::Renderer2D* renderer)
	{				
		renderer->setUVRect(0, 0, 1, 1);
		renderer->drawSprite(mTexture, (position.xPos * 51) + 25, (position.yPos * 51) + 25, 50, 50);
	}

	bool operator==(const Tile& rhs)
	{
		return position == rhs.position;
	}

	void AddEntity(Entity& entity)
	{
		if(!mEntityList->Search(entity))
			mEntityList->InsertLast(entity);
	}

	void RemoveEntity(Entity& entity)
	{
		mEntityList->DeleteNode(entity);
	}

	Vector2 GetPosition()
	{
		return position;
	}
};