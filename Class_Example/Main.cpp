#include "WumpusWorldApplication.h"
#include "Refs.h"
#include "Vector2D.h"

int main()
{
	// allocation
	auto app = new WumpusWorldApplication();

	// initialise and loop
	app->run("AIE", SCREEN_WIDTH, SCREEN_HEIGHT, false);

	// deallocation
	delete app;

	return 0;
}