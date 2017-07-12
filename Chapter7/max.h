#pragma once

int max(int source[], int size)
{
	if (size == 1)
		return source[0];
	else
		return source[0] > max(++source, --size) ? source[0] : max(++source, --size);
}