#include "Camera.h"

Camera::Camera()
{

}

Camera::Camera(Vector2 position)
{
	mPosition = position;
}

Vector2 Camera::GetPosition()
{
	return mPosition;
}
