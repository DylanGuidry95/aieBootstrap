#include "FreelookCamera.h"
#include "Input.h"

FreelookCamera::FreelookCamera()
{
}

FreelookCamera::FreelookCamera(Vector2 position, float movementSpeed) : Camera(position)
{
	mMovementSpeed = movementSpeed;
}

void FreelookCamera::Start()
{
}

void FreelookCamera::Update(float dt)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		mPosition = mPosition + Vector2::Create(0, mMovementSpeed * dt);
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		mPosition = mPosition + Vector2::Create(0, -mMovementSpeed * dt);
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		mPosition = mPosition + Vector2::Create(mMovementSpeed * dt, 0);
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		mPosition = mPosition + Vector2::Create(-mMovementSpeed * dt, 0);	
}

void FreelookCamera::SetLookAt(Vector2 position)
{
	mPosition = position;
}
