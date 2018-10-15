#include "WumpusApp.h"

int main() 
{	
	LinkedList::LinkedListType<int> *a = new LinkedList::UnorderedLinkedList<int>();
	// allocation
	auto app = new WumpusApp();

	// initialise and loop
	app->run("Wumpus", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}