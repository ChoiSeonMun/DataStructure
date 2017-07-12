#pragma once

#ifndef __ACKERMANN_H__
#define __ACKERMANN_H__

//Problem Program Project 4
//��Ŀ�� �Լ��� å�� �߸��Ǿ� �־�, https://en.wikipedia.org/wiki/Ackermann_function �� �����Ѵ�.
unsigned ackermann(unsigned m, unsigned n)
{
	if (m == 0)
		return n + 1;
	if (n == 0)
		return ackermann(m - 1, 1);
	return ackermann(m - 1, ackermann(m, n - 1));
}
#endif