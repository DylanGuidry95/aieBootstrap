#pragma once

namespace Math
{
	class Vector2D
	{
	private:
		float mXPos, mYPos;
	public:
		Vector2D();
		Vector2D(float x, float y);
		float GetX();
		float GetY();
		Vector2D operator+(Vector2D& other);
		Vector2D operator+=(Vector2D& other);
		Vector2D operator-(Vector2D& other);
		Vector2D operator-=(Vector2D& other);
		bool operator==(Vector2D* other);
		bool operator!=(Vector2D* other);
		Vector2D operator=(Vector2D* other);
	};
}