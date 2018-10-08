#pragma once
#include "Vector2.h"

class Camera
{
protected:
	Vector2 mPosition;

public:
	Camera();
	Camera(Vector2 position);

	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void SetLookAt(Vector2 position) = 0;
	Vector2 GetPosition();
};