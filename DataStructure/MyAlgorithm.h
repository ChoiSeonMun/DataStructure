#pragma once

#ifndef __MYALGORITHM_H__
#define __MYALGORITHM_H__

//Problem 1, 3

//Time complexity of A : O(1)
int sumAlgorithmA(int n)
{
	return (n * (n + 1)) / 2;
}

//Time complexity of B : O(n)
int sumAlgorithmB(int n)
{
	int result = 0;
	for (int i = 1; i <= n; ++i)
		result += i;
	return result;
}

//Time complexity of C : O(n^2)
int sumAlgorithmC(int n)
{
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
			++result;
	}
	return result;
}
#endif