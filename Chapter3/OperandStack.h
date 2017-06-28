#pragma once

#ifndef __OPERANDSTACK_H__
#define __OPERANDSTACK_H__

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

constexpr int MAX_STACK_SIZE = 20;

inline void error(char* message);

class OperandStack {
public:
	OperandStack()
		: top(-1), data() { }
	~OperandStack() = default;

	void push(double item);
	double pop();
	double peek();
	bool isEmpty() { return top == -1 ? true : false; }
	bool isFull() { return top == MAX_STACK_SIZE ? true : false; }
	void display();
private:
	int top;
	double data[MAX_STACK_SIZE];
};

inline void OperandStack::push(double item)
{
	if (isFull())
		error("This stack is full");
	else
	{
		top += 1;
		data[top] = item;
	}
}

inline double OperandStack::pop()
{
	if (isEmpty())
		error("This stack is empty");
	else
		return data[top--];
}

inline double OperandStack::peek()
{
	if (isEmpty())
		error("This stack is empty");
	else
		return data[top];
}

inline void OperandStack::display()
{
	printf("[The number of items of the stack : %2d] ==> ", top + 1);
	for (int i = 0; i <= top; ++i)
		printf("<%2.3f>", data[i]);
	printf("\n");
}

inline void error(char * message)
{
	printf("%s\n", message);
	Sleep(5000);
	exit(1);
}
#endif