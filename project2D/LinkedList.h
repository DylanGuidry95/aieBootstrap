#pragma once
#include "LinkedListIterator.h"
#include <cassert>
#include <iostream>

namespace LinkedList
{
	template<typename T>
	class LinkedListType
	{
	protected:
		//Variable to store the the number of elements in the list
		int mCount;
		//pointer to the first node of the list
		Node<T> *mFirst;
		//pointer to the last node of the list
		Node<T> *mLast;
	public:
		//Overload the assignment operator
		const LinkedListType<T>& operator=(const LinkedListType<T>& right)
		{
			CopyList(right)
		}

		//Initialize the lit to an empty state
		//Postcondition: first = NULL, last = NULL, count = 0
		void InitializeList()
		{
			mFirst = nullptr;
			mLast = nullptr;
			mCount = 0;
		}

		//Function to determine wheather the list is empty
		//Postcondition: Returns true if the list is empty otherwise it returns false
		bool IsEmptyList() const
		{
			return (mCount == 0);
		}

		//Function to output the data contained in each node
		//Postcondition: none
		void Print() const
		{
			Node<T> *iter = mFirst;
			while (iter != nullptr)
			{
				std::cout << iter->mInfo << std::endl;
				iter = iter->link;
			}
		}

		//Function to return the number of nodes in the list
		//Postcondition: the value of count is returned
		int Length() const
		{
			return mCount;
		}

		//Function to delete all the nodes from the list
		//Postcondition: first = NULL, last = NULL, count - 0;
		void DestroyList()
		{
			Node<T> *iter = mFirst;
			while (iter != nullptr)
			{
				if (iter->link == nullptr)
				{
					delete iter;
					break;
				}
				Node<T> *temp = iter->link;
				iter = temp;
			}
			mFirst = nullptr;
			mLast = nullptr;
			mCount = 0;
		}

		//Function to return the first element of the list
		//Precondition: The list must exist and must not be empty
		//Postcondition: If the list is empty then the programs terminates; otherwise,
		//				the first element of the list is returned
		T Front() const
		{
			assert(IsEmptyList());
			return mFirst->mInfo;
		}

		//Function to return the last element of the list
		//Precondition: The list must exist and must not be empty
		//Postcondition: If the list is empty then the programs terminates; otherwise,
		//				the last element of the list is returned
		T Back() const
		{
			assert(IsEmptyList());
			return mLast->mInfo;
		}
		
		//Function to determine whether searchItem is in the list
		//Postcondition: Returns true if searchItem is in the list; otherwise, the value
		//				false is returned
		virtual bool Search(const T& searchItem) const = 0;

		//Function to insert newItem at the beginning of the list
		//Postconditon: first points to the new list, newItem is inserted at the begining
		//				of the list, last points to the last node in the list and count
		//				is incremented by 1
		virtual void InsertFirst(const T& newItem) = 0;

		//Function to insert newItem at the end of the list
		//Postconditon: first points to the new list, newItem is inserted at the end
		//				of the list, last points to the last node in the list and count
		//				is incremented by 1
		virtual void InsertLast(const T& newItem) = 0;

		//Function to delete deleteItem from the list
		//Postcondition: If found, the node containing deleteItem is deleted from the 
		//				list. First points to the first node, last points to the last node
		//				of the updated list, adn count is decremented by 1;
		virtual void DeleteNode(const T& deleteItem) = 0;

		//Function to return  an iterator at the begining of the linked list
		//Postcondition: Returns an iterator such that current is set to first
		LinkedListIterator<T> Begin()
		{
			return LinkedListIterator<T>(mFirst);
		}

		//Function to return  an iterator at the end of the linked list
		//Postcondition: Returns an iterator such that current is set to NULL
		LinkedListIterator<T> End()
		{
			return LinkedListIterator<T>(nullptr);
		}

		//Default constructor
		//Initializes the list to an empty state
		//Postcondition: first = NULL, last = NULL, count = 0
		LinkedListType()
		{
			InitializeList();
		}

		//Copy constructor
		LinkedListType(const LinkedListType<T>& other)
		{
			InitializeList();
			CopyList(other);
		}

		//destructor
		//Deletes all the nodes from the list
		//Postcondition: The list object is destroyed
		~LinkedListType()
		{
			DestroyList();
		}

	private:
		//Function to make a copy of otherList
		//Postcondition: A copy of otherList is created and assigned to this list
		void CopyList(const LinkedListType<T>& otherList)
		{
			if(!IsEmptyList())
				DestroyList();
			Node<T>* iter = otherList.mFirst;
			while (iter != nullptr)
			{
				InsertLast(iter->mInfo);
				iter = iter->link;
			}
		}
	};
}
