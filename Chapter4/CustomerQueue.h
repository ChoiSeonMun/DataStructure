#pragma once

#ifndef __CUSTOMERQUEUE_H__
#define __CUSTOMERQUEUE_H__

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include "Customer.h"

constexpr int MAX_QUEUE_SIZE = 100;

class CustomerQueue {
public:
	CustomerQueue()
		: front(0), rear(0) { }

	void enqueue(Customer& item);
	Customer dequeue();
	Customer peek() const;
	bool isEmpty() const { return front == rear; }
	bool isFull() const;
protected:
	int front = 0;
	int rear = 0;
	Customer data[MAX_QUEUE_SIZE];
	void error(char* msg) const { puts(msg); Sleep(5000); exit(1); }
};

void CustomerQueue::enqueue(Customer& item)
{
	if (isFull()) error("The queue is full");

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = item;
}

Customer CustomerQueue::dequeue()
{
	if (isEmpty()) error("The queue is empty");

	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Customer CustomerQueue::peek() const
{
	if (isEmpty()) error("The queue is empty");

	return data[(front + 1) % MAX_QUEUE_SIZE];
}

inline bool CustomerQueue::isFull() const
{
	return ((rear + 1) % MAX_QUEUE_SIZE) == front;
}

#endif