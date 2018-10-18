#pragma once
#include "application.h"


namespace aie
{
	class Renderer2D;
	class Font;
}

class WumpusWorldApplication : public aie::Application
{
private:
	aie::Renderer2D *mRenderer;
	aie::Font* mDefaultFont;
public:
	WumpusWorldApplication() {}
	~WumpusWorldApplication() {}
	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;
};