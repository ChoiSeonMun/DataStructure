#include <cstdio>
#include "isHeapRecurh.h"
#include "isHeapIter.h"

int main()
{
	int heap[] = { 0, 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	if (isHeapIter(heap, 10))
		puts("True");
	else
		puts("False");

	return 0;
}