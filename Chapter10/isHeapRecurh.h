#pragma once

#ifndef __ISHEAPRECUR_H__
#define __ISHEAPRECUR_H__

//Problem Program Project 3
bool isHeapRecur(int heap[], int size)
{
	if (size == 1)
		return true;
	else if (heap[size / 2] < heap[size])
		return false;
	else
		return isHeapRecur(heap, --size);
}
#endif