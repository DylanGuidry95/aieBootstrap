#include "WumpusApp.h"
#include "Texture.h"

std::ostream& operator<<(std::ostream& os, const Vector2& data)
{
	os << "<" << data.xPos << "," << data.yPos << ">";
	return os;
}

WumpusApp::WumpusApp()
{
	
}

WumpusApp::~WumpusApp()
{

}

bool WumpusApp::startup()
{
	mRenderer = new aie::Renderer2D();
	mCam = new FreelookCamera(Vector2::Create(0,0), 500);
	mDungeon = new Dungeon(10,10);	
	mPlayerController = new PlayerController();
	mWumpus = new Wumpus();
	mDungeon->SetPlayer(mPlayerController->GetPlayer());
	mDungeon->SetWumpus(mWumpus);	
	mTimer = 0;	
	return true;
}

void WumpusApp::shutdown()
{
	delete mRenderer;
}

void WumpusApp::update(float deltaTime)
{
	mTimer += deltaTime;	
	int a = ((rand() % 4) + 1);
	if(a == 1)
		mWumpus->SetDirection(Direction::NORTH);
	if (a == 2)
		mWumpus->SetDirection(Direction::EAST);
	if (a == 3)
		mWumpus->SetDirection(Direction::SOUTH);
	if (a == 4)
		mWumpus->SetDirection(Direction::WEST);
	mPlayerController->Update();
	mDungeon->Update();
}

void WumpusApp::draw()
{
	clearScreen();

	mRenderer->setCameraPos(mCam->GetPosition().xPos, mCam->GetPosition().yPos);

	mRenderer->begin();	

	mDungeon->Draw(mRenderer);
	mPlayerController->GetPlayer()->Draw(mRenderer);
	mWumpus->Draw(mRenderer);

	mRenderer->end();
}