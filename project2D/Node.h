#pragma once

namespace LinkedList
{
	template<typename T>
	struct Node
	{
		T *mInfo;
		Node<T> *link;
	};
}