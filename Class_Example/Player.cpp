#include "Player.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Input.h"

void Player::Start()
{

}

void Player::Update(float dt)
{
	aie::Input* input = aie::Input::getInstance();
	Math::Vector2D pos = *mPosition;
	if (input->isKeyDown(aie::INPUT_KEY_W))
		pos += Math::Vector2D(0, 1) * mMovementSpeed;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		pos += Math::Vector2D(0, 1) * mMovementSpeed;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		pos += Math::Vector2D(-1, 0) * mMovementSpeed;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		pos += Math::Vector2D(1, 0) * mMovementSpeed;
}


Player::Player() : GameObject()
{
	mMovementSpeed = 0;
	mRotation = 0;
}

Player::Player(Math::Vector2D pos, float movementSpeed, float rotation,
	aie::Texture *texture) : GameObject(pos, texture)
{
	mMovementSpeed = movementSpeed;
	mRotation = rotation;
}