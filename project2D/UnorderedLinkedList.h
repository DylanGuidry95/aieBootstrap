#pragma once
#include "LinkedList.h"

namespace LinkedList
{
	template<typename T>
	class UnorderedLinkedList : public LinkedListType<T>
	{
	public:
		//Function to determine whether searchItem is in the list
		//Postcondition: Returns true if searchItem is in the list; otherwise, the value
		//				false is returned
		bool Search(const T& searchItem) const override
		{
			if (IsEmptyList())
				return false;
			Node<T> *iter = mFirst;
			while (iter != nullptr)
			{
				if (iter->mInfo == searchItem)
					return true;
				iter = iter->link;
			}
			return false;
		}

		//Function to insert newItem at the beginning of the list
		//Postconditon: first points to the new list, newItem is inserted at the begining
		//				of the list, last points to the last node in the list and count
		//				is incremented by 1
		void InsertFirst(const T& newItem) override
		{
			Node<T> *newNode = new Node<T>{ newItem, nullptr };
			if (IsEmptyList())
			{
				mFirst = newNode;
				mLast = newNode;
				mCount++;
				return;
			}
			newNode->link = mFirst;
			mFirst = newNode;
		}

		//Function to insert newItem at the end of the list
		//Postconditon: first points to the new list, newItem is inserted at the end
		//				of the list, last points to the last node in the list and count
		//				is incremented by 1
		void InsertLast(const T& newItem) override
		{
			Node<T> *newNode = new Node<T>{ newItem, nullptr };
			if (IsEmptyList())
			{
				mFirst = newNode;
				mLast = newNode;
				mCount++;
				return;
			}			
			mLast->link = newNode;
			mLast = newNode;
		}

		//Function to delete deleteItem from the list
		//Postcondition: If found, the node containing deleteItem is deleted from the 
		//				list. First points to the first node, last points to the last node
		//				of the updated list, adn count is decremented by 1;
		void DeleteNode(const T& deleteItem) override
		{
			Node<T> *iter = mFirst;
			if (iter == nullptr)
				return;
			while (iter->link != nullptr)
			{				
				if (iter->mInfo == deleteItem)
				{
					if (iter == mFirst)
					{
						Node<T> *temp = iter;
						mFirst = temp->link;
						delete temp;
						break;
					}
				}
				if (iter->link->mInfo == deleteItem)
				{
					Node<T>* temp = iter->link;
					if (iter->link == mLast)
					{
						mLast = iter;
						delete iter;
						mLast->link = nullptr;
						break;
					}
					iter->link = temp->link;
					delete temp;
					break;
				}
				iter = iter->link;
			}			
		}
	};
}