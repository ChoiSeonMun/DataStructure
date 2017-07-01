#pragma once

#ifndef __CALCULATEFIBONACCI_H__
#define __CALCULATEFIBONACCI_H__

#include <queue>

//Problem Practice 8
//Feature : to calculate fibonacci numbers
//Return : the 'num'th number
unsigned calculateFibonacci(unsigned num)
{
	if (num == 0) return 0;
	if (num == 1) return 1;

	std::queue<unsigned> fiboBase;
	fiboBase.push(0);
	fiboBase.push(1);
	for (unsigned i = 2; i <= num; ++i)
	{
		unsigned temp = fiboBase.front();
		fiboBase.pop();
		fiboBase.push(temp + fiboBase.front());
	}
	fiboBase.pop();

	return fiboBase.front();
}

#endif