#pragma once
#include "Camera.h"

class FreelookCamera : public Camera
{
private:
	float mMovementSpeed;

public:
	FreelookCamera();
	FreelookCamera(Vector2 position, float movementSpeed);
	void Start() override;
	void Update(float dt) override;
	void SetLookAt(Vector2 position) override;
};