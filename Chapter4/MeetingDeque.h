#pragma once

#ifndef __MEETINGDEQUE_H__
#define __MEETINGDEQUE_H__

#include "MeetingQueue.h"

class MeetingDeque : public MeetingQueue {
public:
	void addFront(char* item);
	char* deleteFront() { return dequeue(); }
	char* getFront() const { return peek(); }
	void addRear(char* item) { enqueue(item); }
	char* deleteRear();
	char* getRear() const;
};

void MeetingDeque::addFront(char* item)
{
	if (isFull()) throw std::exception("The deque is full");

	data[front--] = item;
	if (front < 0) front = MAX_QUEUE_SIZE - 1;
}

char* MeetingDeque::deleteRear()
{
	if (isEmpty()) throw std::exception("The deque is empty");

	char* result = data[rear--];
	if (rear < 0) rear = MAX_QUEUE_SIZE - 1;

	return result;
}

char* MeetingDeque::getRear() const
{
	if (isEmpty()) throw std::exception("The deque is empty");

	return data[rear];
}

#endif