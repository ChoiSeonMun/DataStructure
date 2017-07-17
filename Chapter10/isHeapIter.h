#pragma once

#ifndef __ISHEAPITER_H__
#define __ISHEAPITER_H__

bool isHeapIter(int heap[], int size)
{
	for (int i = size; i > 1; --i)
	{
		if (heap[i / 2] < heap[i])
			return false;
	}
	
	return true;
}
#endif