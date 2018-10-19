#include "GameObject.h"
#include "Renderer2D.h"
#include "Vector2D.h"

GameObject::GameObject()
{
	mPosition = new Math::Vector2D(0, 0);
	mTexture = new aie::Texture("./textures/ball.png");
}

GameObject::GameObject(Math::Vector2D pos, aie::Texture *texture)
{
	mPosition = &pos;
	mTexture = texture;
}

GameObject::~GameObject()
{
	delete mPosition;
	delete mTexture;
}


void GameObject::Draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(mTexture, (mPosition->GetX() + 1) * 
		50, (mPosition->GetY() + 1) * 50, 50,50, mRotation);
}

Math::Vector2D GameObject::GetPosition()
{
	return *mPosition;
}

float GameObject::GetRotation()
{
	return mRotation;
}

float GameObject::GetMovementSpeed()
{
	return mMovementSpeed;
}

void GameObject::SetPosition(Math::Vector2D pos)
{
	*mPosition = pos;
}

void GameObject::SetRotation(float rot)
{
	mRotation = rot;
}

void GameObject::SetSpeed(float speed)
{
	mMovementSpeed = speed;
}
