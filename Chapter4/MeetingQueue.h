#pragma once

#ifndef __MEETINGQUEUE_H__
#define __MEETINGRQUEUE_H__

//Problem Programming Project 1-2
#include <cstdio>
#include <cstdlib>
#include <exception>

constexpr int MAX_QUEUE_SIZE = 100;

class MeetingQueue {
public:
	void enqueue(char* item);
	char* dequeue();
	char* peek() const;
	bool isEmpty() const { return front == rear; }
	bool isFull() const;
protected:
	int front = 0;
	int rear = 0;
	char* data[MAX_QUEUE_SIZE];
};

void MeetingQueue::enqueue(char* item)
{
	if (isFull()) throw std::exception("The queue is full");

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = item;
}

char* MeetingQueue::dequeue()
{
	if (isEmpty()) std::exception("The queue is empty");

	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

char* MeetingQueue::peek() const
{
	if (isEmpty()) std::exception("The queue is empty");

	return data[(front + 1) % MAX_QUEUE_SIZE];
}

inline bool MeetingQueue::isFull() const
{
	return ((rear + 1) % MAX_QUEUE_SIZE) == front;
}
#endif