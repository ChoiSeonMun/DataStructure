#pragma once

#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

#include "Node.h"

class LinkedQueue {
public:
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }

	bool	isEmpty() { return front == nullptr; }
	void	enqueue(Node* item);
	Node*	dequeue();
	Node*	peek() { return front; }
	void	display();
private:
	Node*	front = nullptr;
	Node*	rear = nullptr;
};

void LinkedQueue::enqueue(Node * item)
{
	if (isEmpty())
		front = rear = item;
	else
	{
		rear->setLink(item);
		rear = item;
	}
}

Node * LinkedQueue::dequeue()
{
	if (isEmpty())	return nullptr;

	Node* result = front;
	if (front == rear)
		front = rear = nullptr;
	else
		front = front->getLink();
	
	return result;
}

void LinkedQueue::display()
{
	puts("Queue Contents");
	puts("-------------------");
	for (Node* link = front; link != nullptr; link = link->getLink())
		link->display();
	puts("");
}
#endif