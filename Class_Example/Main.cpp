#include "WumpusWorldApplication.h"
#include "Vector2D.h"

int main()
{
	// allocation
	auto app = new WumpusWorldApplication();

	// initialise and loop
	app->run("AIE", 1080, 720, false);

	// deallocation
	delete app;

	return 0;
}