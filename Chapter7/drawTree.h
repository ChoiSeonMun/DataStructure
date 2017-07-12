#pragma once

#ifndef __DRAWTREE_H__
#define __DRAWTREE_H__

//Problem Program Project 5
#include <cstdio>

void drawTree(int row, int left, int right)
{
	if (row == 0)
	{
		for (int i = left; i <= right; ++i)
		{
			if (i == (left + right) / 2)
				printf("X");
			else
				printf("-");
		}
	}
	else
	{
		drawTree(row - 1, left, (left + right) / 2);
		drawTree(row - 1, (left + right) / 2 + 1, right);
	}
}
#endif