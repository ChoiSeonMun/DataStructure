#pragma once

#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

//Problem Program Project 1
#include <cstdio>
#include <cstring>

long* counts;

void initialize(long num)
{
	counts = new long[num + 1];
	memset(counts, 0, sizeof(long) * (num + 1));
}

long fibonacci(long num)
{
	++counts[num];

	if (num <= 1)
		return num;
	else
		return fibonacci(num - 1) + fibonacci(num - 2);
}

//Problem 2 Program Project 2
void fibonacci()
{
	long tmp, current = 1, last = 0;
	int count = 2;
	while (current > 0)
	{
		tmp = current;
		current += last;
		last = tmp;
		printf("È½¼ö : %d, °ª : %ld\n", count++, current);
	}
}
#endif