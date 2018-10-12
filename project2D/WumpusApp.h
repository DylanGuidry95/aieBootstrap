#pragma once
#include "Application.h"
#include "Dungeon.h"
#include "FreelookCamera.h"
#include "PlayerController.h"
#include "WumpusController.h"

class WumpusApp : public aie::Application
{
private:
	aie::Renderer2D *mRenderer;	
	Camera *mCam;
	Dungeon * mDungeon;
	Wumpus* mWumpus;
	PlayerController *mPlayerController;
	WumpusController *mWumpusController;
	float mTimer;	

public:
	WumpusApp();
	~WumpusApp();
	
	bool startup() override;
	void shutdown() override;
	
	void update(float deltaTime) override;
	void draw() override;
};
