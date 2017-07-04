#include "Maze.h"

//Problem Program Project 1-2
int main()
{
	Maze maze;
	maze.load("maze.txt");
	maze.print();
	maze.searchExit();
	maze.print();

	return 0;
}