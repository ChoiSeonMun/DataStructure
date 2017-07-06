#pragma once

#ifndef __LINE_H__
#define __LINE_H__

#include <cstring>
#include <cstdio>

constexpr int MAX_DATA_SIZE = 200;
class Line {
public:
	Line(char* content) { strcpy_s(data, MAX_DATA_SIZE, content); }

	void	print(FILE* file) { fputs(data, file); }
	bool	hasData(char* content) { return !strcmp(data, content); }
private:
	char	data[MAX_DATA_SIZE];
};
#endif