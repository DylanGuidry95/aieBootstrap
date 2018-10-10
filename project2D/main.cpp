#include "WumpusApp.h"
#include "LinkedListIterator.h"

int main() 
{	
	//LinkedList::Node<int> a = LinkedList::Node<int>{ 1, nullptr };
	//LinkedList::Node<int> b = LinkedList::Node<int>{ 2, &a };
	//LinkedList::Node<int> c = LinkedList::Node<int>{ 3, &b };
	//LinkedList::Node<int> d = LinkedList::Node<int>{ 4, &c };

	//LinkedList::LinkedListIterator<int> iterator = LinkedList::LinkedListIterator<int>(&d);
	//LinkedList::LinkedListIterator<int> *iter2 = iterator++;
	//bool test = iterator == iter2;

	// allocation
	auto app = new WumpusApp();

	// initialise and loop
	app->run("Wumpus", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}