#include "WumpusWorldApplication.h"
#include "Renderer2D.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Vector2D.h"
#include "Refs.h"

bool WumpusWorldApplication::startup()
{
	mRenderer = new aie::Renderer2D();	
	mDefaultFont = new aie::Font("./font/consolas.ttf", 32);
	mPlayer = new Player(Math::Vector2D(0, 0), 2);
	return true;
}

void WumpusWorldApplication::shutdown()
{
	delete mRenderer;
}

void WumpusWorldApplication::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	mPlayer->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void WumpusWorldApplication::draw()
{
	clearScreen();	
	//Set Camera
	mRenderer->setCameraPos(0, 0);
	
	mRenderer->begin();

	//Draw Stuff
	mPlayer->Draw(mRenderer);

	mRenderer->setRenderColour(1, 1, 1, 1);
	mRenderer->drawText(mDefaultFont, "Press ESC to quit", 0, 0);

	mRenderer->end();
}
