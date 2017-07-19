#pragma once

#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

constexpr int MAX_STACK_SIZE = 20;

inline void error(char* message);

class ArrayStack {
public:
	ArrayStack()
		: top(-1), data() { }
	~ArrayStack() = default;

	void push(int item);
	int pop();
	int peek();
	bool isEmpty() { return top == -1 ? true : false; }
	bool isFull() { return top == MAX_STACK_SIZE ? true : false; }
	void display();
private:
	int top;
	int data[MAX_STACK_SIZE];
};

inline void ArrayStack::push(int item)
{
	if (isFull())
		error("This stack is full");
	else
	{
		top += 1;
		data[top] = item;
	}
}

inline int ArrayStack::pop()
{
	if (isEmpty())
		error("This stack is empty");
	else
		return data[top--];
}

inline int ArrayStack::peek()
{
	if (isEmpty())
		error("This stack is empty");
	else
		return data[top];
}

inline void ArrayStack::display()
{
	printf("[The number of items of the stack : %2d] ==> ", top + 1);
	for (int i = 0; i <= top; ++i)
		printf("<%2d>", data[i]);
	printf("\n");
}

inline void error(char * message)
{
	printf("%s\n", message);
	Sleep(5000);
	exit(1);
}
#endif