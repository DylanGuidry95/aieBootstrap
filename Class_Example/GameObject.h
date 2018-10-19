#pragma once
#include "Texture.h"

namespace Math
{
	class Vector2D;
}

namespace aie
{	
	class Renderer2D;
}

class GameObject
{
protected:
	Math::Vector2D* mPosition;
	aie::Texture* mTexture;
	float mRotation;
	float mMovementSpeed;
public:
	GameObject();
	GameObject(Math::Vector2D pos, 
		aie::Texture* texture = new aie::Texture("./textures/ball.png"));
	~GameObject();
	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	void Draw(aie::Renderer2D* renderer);
	Math::Vector2D GetPosition();
	float GetRotation();
	float GetMovementSpeed();
	void SetPosition(Math::Vector2D pos);
	void SetRotation(float rot);
	void SetSpeed(float speed);
};