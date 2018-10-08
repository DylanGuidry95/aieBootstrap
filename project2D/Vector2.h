#pragma once
#include <iostream>
struct Vector2
{
	float xPos;
	float yPos;
	static Vector2 Create(float x, float y)
	{
		Vector2 newVec;
		newVec.xPos = x;
		newVec.yPos = y;
		return newVec;
	}

	Vector2 operator+(const Vector2& rhs)
	{
		Vector2 newVector;
		newVector.xPos = this->xPos + rhs.xPos;
		newVector.yPos = this->yPos + rhs.yPos;
		return newVector;
	}

	Vector2 operator-(const Vector2& rhs)
	{
		Vector2 newVector;
		newVector.xPos = this->xPos - rhs.xPos;
		newVector.yPos = this->yPos - rhs.yPos;
		return newVector;
	}

	Vector2 operator=(const Vector2& rhs)
	{
		xPos = rhs.xPos;
		yPos = rhs.yPos;
		return *this;
	}

	bool operator==(const Vector2& rhs)
	{
		return (xPos == rhs.xPos && yPos == rhs.yPos);
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& data);
};