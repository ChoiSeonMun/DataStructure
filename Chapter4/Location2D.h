#pragma once

#ifndef __LOCATION2D_H__
#define __LOCAIOTN2D_H__

struct Location2D {
	int row;
	int col;

	Location2D(int r = 0, int c = 0)
		: row(r), col(c) { }

	bool isNeighbor(Location2D& p)
	{
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| col == p.col && (row == p.row - 1 || row == p.row + 1));
	}

	bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};
#endif
