#include "Vector2D.h"

Math::Vector2D::Vector2D()
{
	mXPos = mYPos = 0;
}

Math::Vector2D::Vector2D(float x, float y)
{
	mXPos = x;
	mYPos = y;
}

float Math::Vector2D::GetX()
{
	return mXPos;
}

float Math::Vector2D::GetY()
{
	return mYPos;
}

Math::Vector2D Math::Vector2D::operator+(const Vector2D& other)
{
	return Math::Vector2D(mXPos + other.mYPos, mYPos + other.mYPos);
}

Math::Vector2D Math::Vector2D::operator+=(const Vector2D& other)
{
	*this = Math::Vector2D(mXPos + other.mYPos, mYPos + other.mYPos);
	return *this;
}

Math::Vector2D Math::Vector2D::operator-(const Vector2D& other)
{
	return Math::Vector2D(mXPos - other.mYPos, mYPos - other.mYPos);
}

Math::Vector2D Math::Vector2D::operator-=(const Vector2D& other)
{
	*this = Math::Vector2D(mXPos - other.mYPos, mYPos - other.mYPos);
	return *this;
}

Math::Vector2D Math::Vector2D::operator*(const float other)
{
	return Vector2D(mXPos * other, mYPos * other);
}

bool Math::Vector2D::operator==(const Vector2D& other)
{
	return(mXPos == other.mXPos && mYPos == other.mYPos);
}

bool Math::Vector2D::operator!=(const Vector2D& other)
{
	return(mXPos != other.mXPos && mYPos != other.mYPos);
}

Math::Vector2D Math::Vector2D::operator=(const Vector2D& other)
{
	mXPos = other.mXPos;
	mYPos = other.mYPos;
	return *this;
}