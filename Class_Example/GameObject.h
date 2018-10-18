#pragma once

namespace Math
{
	class Vector2D;
}

namespace aie
{
	class Texture;
	class Renderer2D;
}

class GameObject
{
protected:
	Math::Vector2D* mPosition;
	aie::Texture* mTexture;
public:
	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(aie::Renderer2D* renderer) = 0;
};