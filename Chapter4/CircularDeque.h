#pragma once

#ifndef __CIRCULARDEQUE_H__
#define __CIRCULARDEQUE_H__

#include "CircularQueue.h"

class CircularDeque : public CircularQueue {
public:
	void addFront(int item);
	int deleteFront() { return dequeue(); }
	int getFront() const { return peek(); }
	void addRear(int item) { enqueue(item); }
	int deleteRear();
	int getRear() const;
	void display() const override;
};

void CircularDeque::addFront(int item)
{
	if (isFull()) error("The deque is full");

	data[front--] = item;
	if (front < 0) front = MAX_QUEUE_SIZE - 1;
}

int CircularDeque::deleteRear()
{
	if (isEmpty())	error("The deque is empty");

	int result = data[rear--];
	if (rear < 0) rear = MAX_QUEUE_SIZE - 1;

	return result;
}

int CircularDeque::getRear() const
{
	if (isEmpty()) error("The deque is empty");

	return data[rear];
}

void CircularDeque::display() const
{
	int end = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
	for (int i = front + 1; i <= end; ++i)
		printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
	puts("");
}
#endif