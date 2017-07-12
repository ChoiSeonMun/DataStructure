#pragma once

#ifndef __REVERSE_H__
#define __REVERSE_H__

#include <cstdio>

void reverse(char* source)
{
	if (*source == '\0')
		return;
	else
	{
		reverse(++source);
		printf("%c", *--source);
	}
}
#endif