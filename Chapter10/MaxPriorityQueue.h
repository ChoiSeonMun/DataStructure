#pragma once

#ifndef __MAXPRIORITYQUEUE_H__
#define __MAXPRIORITYQUEUE_H__

//Problem Program Project 1
#include <cstdio>

constexpr int MAX_ELEMENT = 100;

class MaxPriorityQueue {
public:
	MaxPriorityQueue()
		: elem(), size(-1) { }

	bool	isEmpty() { return size == -1; }
	bool	isFull() { return size == MAX_ELEMENT - 1; }
	void	insert(int elem);
	int		remove();
	int		find();
	void	display();
private:
	int		elem[MAX_ELEMENT];
	int		size;
};

void MaxPriorityQueue::insert(int elem)
{
	if (!isFull())
		this->elem[++size] = elem;
}

int MaxPriorityQueue::remove()
{
	if (isEmpty())
	{
		puts("큐가 비어있습니다.");
		return -1;
	}

	int maxIdx = 0;
	int max = elem[0];
	for (int i = 1; i <= size; ++i)
	{
		if (max < elem[i])
		{
			max = elem[i];
			maxIdx = i;
		}
	}
	for (int i = maxIdx; i <= size - 1; ++i)
		elem[i] = elem[i + 1];
	--size;

	return max;
}

int MaxPriorityQueue::find()
{
	if (isEmpty())
	{
		puts("큐가 비어있습니다.");
		return -1;
	}

	int max = elem[0];
	for (int i = 1; i <= size; ++i)
	{
		if (max < elem[i])
			max = elem[i];
	}

	return max;
}

void MaxPriorityQueue::display()
{
	puts("우선순위 큐 요소");
	puts("------------------------");
	for (int i = 0; i <= size; ++i)
		printf("[%2d] ", elem[i]);
	puts("");
}
#endif