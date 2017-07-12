#pragma once

#ifndef __ACKERMANN_H__
#define __ACKERMANN_H__

//Problem Program Project 4
//아커만 함수가 책에 잘못되어 있어, https://en.wikipedia.org/wiki/Ackermann_function 를 참조한다.
unsigned ackermann(unsigned m, unsigned n)
{
	if (m == 0)
		return n + 1;
	if (n == 0)
		return ackermann(m - 1, 1);
	return ackermann(m - 1, ackermann(m, n - 1));
}
#endif