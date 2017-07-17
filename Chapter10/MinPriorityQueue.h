#pragma once

#ifndef __MINPRIORITYQUEUE_H__
#define __MINPRIORITYQUEUE_H__

//Problem Program Project 2
#include "Node.h"
#include <cstdio>

class MinPriorityQueue {
public:
	MinPriorityQueue()
		: min(nullptr), size(0) { }

	bool	isEmpty() { return size == 0; }
	void	insert(int elem);
	int		remove();
	int		find() { return min->getKey(); }
	void	display();
private:
	Node*	min;
	int		size;	//Why is this needed?
};

void MinPriorityQueue::insert(int elem)
{
	if (!min)
		min = new Node(elem);
	else
	{
		Node* prev = nullptr;
		Node* current = min;
		while (current)
		{
			if (elem < current->getKey())
			{
				if (current == min)
				{
					min->insertNext(new Node(min->getKey()));
					min->setKey(elem);
				}
				else
					prev->insertNext(new Node(elem));

				break;
			}
			prev = current;
			current = current->getNext();
		}
		if (!current)
			prev->insertNext(new Node(elem));
	}
	++size;
}

int MinPriorityQueue::remove()
{
	Node* minNode = min;
	min = min->getNext();
	int minVal = minNode->getKey();
	delete minNode;
	--size;

	return minVal;
}

void MinPriorityQueue::display()
{
	puts("우선순위 큐 요소");
	puts("-------------------");
	Node* current = min;
	while (current)
	{
		printf("[%2d] ", current->getKey());
		current = current->getNext();
	}
	puts("");
}
#endif