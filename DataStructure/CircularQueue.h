#pragma once

#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

constexpr int MAX_QUEUE_SIZE = 100;

class CustomerQueue {
public:
	void enqueue(int item);
	int dequeue();
	int peek() const;
	bool isEmpty() const { return front == rear; }
	bool isFull() const;
	virtual void display() const;
protected:
	int front = 0;
	int rear = 0;
	int data[MAX_QUEUE_SIZE];
	void error(char* msg) const { puts(msg); Sleep(5000); exit(1); }
};

void CustomerQueue::enqueue(int item)
{
	if (isFull()) error("The queue is full");

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = item;
}

int CustomerQueue::dequeue()
{
	if (isEmpty()) error("The queue is empty");
	
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

int CustomerQueue::peek() const
{
	if (isEmpty()) error("The queue is empty");
	
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

inline bool CustomerQueue::isFull() const
{
	return ((rear + 1) % MAX_QUEUE_SIZE) == front;
}

void CustomerQueue::display() const
{
	int end = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
	for (int i = front + 1; i <= end; ++i)
		printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
	puts("");
}
#endif