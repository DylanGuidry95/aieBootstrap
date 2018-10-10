#include "WumpusApp.h"
#include "UnorderedLinkedList.h"

int main() 
{	
	LinkedList::LinkedListType<int> *list = new LinkedList::UnorderedLinkedList<int>();
	list->InsertFirst(0);
	list->InsertLast(1);
	list->InsertLast(2);
	list->InsertLast(3);
	list->InsertFirst(-1);

	bool searchA = list->Search(1);
	bool searchB = list->Search(5);

	list->DeleteNode(2);
	LinkedList::LinkedListType<int> *newList = new LinkedList::UnorderedLinkedList<int>((const LinkedList::UnorderedLinkedList<int>&)list);
	delete list;
	LinkedList::LinkedListIterator<int> testA = list->Begin();
	++testA;
	++testA;
	++testA;
	LinkedList::LinkedListIterator<int> testB = list->End();
	// allocation
	auto app = new WumpusApp();

	// initialise and loop
	app->run("Wumpus", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}