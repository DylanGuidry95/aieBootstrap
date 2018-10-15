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
public:
	Tile()
	{
		mTexture = new aie::Texture("./textures/tile.png");		
		position = Vector2::Create(0, 0);
	}

	Tile(Vector2 pos)
	{
		mTexture = new aie::Texture("./textures/tile.png");		
		position = pos;
	}	

	void Draw(aie::Renderer2D* renderer)
	{				
		renderer->setUVRect(0, 0, 1, 1);
		renderer->drawSprite(mTexture, (position.xPos * 51) + 25,
			(position.yPos * 51) + 25, 50, 50);
	}

	bool operator==(const Tile& rhs)
	{
		return position == rhs.position;
	}

	Vector2 GetPosition()
	{
		return position;
	}
};