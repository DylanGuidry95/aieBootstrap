#pragma once
#include "Node.h"

namespace LinkedList
{
	template<typename T>
	class LinkedListIterator
	{
	private:
		//Pointer to point to the current node in the linked list
		Node<T> *mCurrent;
	public:
		//Default Constructor
		//Postcondition: mCurrent = NULL;
		LinkedListIterator()
		{
			mCurrent = nullptr;
		}

		//Constructor with parameter
		//Postcondition: mCurrent = ptr
		LinkedListIterator(Node<T>* ptr)
		{
			mCurrent = ptr;
		}

		//Function to overload the dereferencing operator *
		//Postcondition: Returns the information contained in the node;
		T operator*()
		{
			return mCurrent->mInfo;
		}

		//Overload the pre-increment operator
		//Postcondition: The iterator is advanced to the next node;
		LinkedListIterator<T> operator++()
		{
			return LinkedListIterator<T>(new Node<T>(mCurrent->link));
		}

		//Overload the equaltiy operator
		//Postcondition: Returns true if this iterator is equal to the 
		//iterator specidfed by right otherwise it returns false.
		bool operator==(const LinkedListIterator<T>& right) const
		{
			return mCurrent == right.mCurrent;
		}

		//Overload the not equaltiy operator
		//Postcondition: Returns true if this iterator is not equal to the 
		//iterator specidfed by right otherwise it returns false.
		bool operator!=(const LinkedListIterator<T>& right) const
		{
			return mCurrent != right.mCurrent;
		}
	};
}