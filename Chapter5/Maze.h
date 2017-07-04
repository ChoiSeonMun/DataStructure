#pragma once

#ifndef __MAZE_H__
#define __MAZE_H__

#include "Location2D.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <cstdio>
#include <cassert>

//Problem Program Project 1-1, 1-3
class Maze {
public:
	Maze() { init(0, 0); }
	~Maze() { reset(); }
	
	void	init(int w, int h);
	void	reset();
	void	load(char* filename);
	void	print();
	void	searchExit();
private:
	enum	MapInfo { WALL = 0, PATH = 1, ENTRANCE = 5, EXPLORE = 7, OPTIMIZATION = 8, EXIT = 9 };
	int		width;
	int		height;
	int**	map;
	Location2D	entranceLoc;

	bool	isValidLoc(int row, int col, bool forOptimized);
};

//Feature : to allocate the map
void Maze::init(int w, int h)
{
	map = new int*[h];
	for (int col = 0; col != h; ++col)
		map[col] = new int[w];
}

void Maze::reset()
{
	for (int col = 0; col != height; ++col)
		delete[] map[col];
	delete[] map;
}

//Feature : to load the map from the file
void Maze::load(char * filename)
{
	//open the file
	FILE* fp;
	fopen_s(&fp, filename, "r");
	assert(fp);
	
	//load the map
	fscanf_s(fp, "%d %d", &width, &height);
	init(width, height);
	for (int row = 0; row != height; ++row)
	{
		for (int col = 0; col != width; ++col)
			fscanf_s(fp, "%d", &map[row][col]);
	}
	fclose(fp);
}

//Feature : to print the map out to the console
void Maze::print()
{
	printf("전체 미로의 크기 = %d X %d\n", width, height);
	for (int row = 0; row != height; ++row)
	{
		for (int col = 0; col != width; ++col)
		{
			switch (map[row][col]) {
			case MapInfo::WALL:
				fputs("■", stdout);
				break;
			case MapInfo::PATH:
				fputs("  ", stdout);
				break;
			case MapInfo::ENTRANCE:
				fputs("○", stdout);
				entranceLoc.row = row;
				entranceLoc.col = col;
				break;
			case MapInfo::EXPLORE:
				fputs("□", stdout);
				break;
			case MapInfo::OPTIMIZATION:
				fputs("☆", stdout);
				break;
			case MapInfo::EXIT:
				fputs("◎", stdout);
				break;
			default:
				assert(!"Unknown data");
				break;
			}
		}
		puts("");	//for '\n'
	}
	puts("");			//for '\n'
}

//Feature : to search exit
void Maze::searchExit()
{
	Node* currentPosition = new Node(entranceLoc.row, entranceLoc.col);
	LinkedStack stack;
	LinkedQueue que;

	//while to find the exit
	while (map[currentPosition->row][currentPosition->col] != MapInfo::EXIT)
	{
		//if topside of current position is vaild, to push that position
		if (isValidLoc(currentPosition->row - 1, currentPosition->col, false))
			que.enqueue(new Node(currentPosition->row - 1, currentPosition->col));
		//bottom
		if (isValidLoc(currentPosition->row + 1, currentPosition->col, false))
			que.enqueue(new Node(currentPosition->row + 1, currentPosition->col));
		//left side
		if (isValidLoc(currentPosition->row, currentPosition->col - 1, false))
			que.enqueue(new Node(currentPosition->row, currentPosition->col - 1));
		//right side
		if (isValidLoc(currentPosition->row, currentPosition->col + 1, false))
			que.enqueue(new Node(currentPosition->row, currentPosition->col + 1));

		//mark
		map[currentPosition->row][currentPosition->col] = MapInfo::EXPLORE;
		
		//move
		delete currentPosition;
		currentPosition = que.dequeue();
	}

	//to search optimized path
	//current position is exit currently
	//while to find the entrance
	while (!(currentPosition->row == entranceLoc.row && currentPosition->col == entranceLoc.col))
	{
		//if topside of current position is vaild, to push that position
		if (isValidLoc(currentPosition->row - 1, currentPosition->col, true))
			stack.push(new Node(currentPosition->row - 1, currentPosition->col));
		//bottom
		if (isValidLoc(currentPosition->row + 1, currentPosition->col, true))
			stack.push(new Node(currentPosition->row + 1, currentPosition->col));
		//right side
		if (isValidLoc(currentPosition->row, currentPosition->col + 1, true))
			stack.push(new Node(currentPosition->row, currentPosition->col + 1));
		//left side
		if (isValidLoc(currentPosition->row, currentPosition->col - 1, true))
			stack.push(new Node(currentPosition->row, currentPosition->col - 1));
		
		//mark
		map[currentPosition->row][currentPosition->col] = MapInfo::OPTIMIZATION;

		//move
		delete currentPosition;
		currentPosition = stack.pop();
	}
	map[currentPosition->row][currentPosition->col] = MapInfo::OPTIMIZATION;
	delete currentPosition;
}

inline bool Maze::isValidLoc(int row, int col, bool forOptimized)
{
	if (row < 0 || col < 0 || row >= height || col >= width)
		return false;
	else if (forOptimized)
		return map[row][col] == ENTRANCE || map[row][col] == EXIT
		|| map[row][col] == PATH || map[row][col] == EXPLORE;
	else
		return map[row][col] == ENTRANCE || map[row][col] == EXIT || map[row][col] == PATH;
}
#endif