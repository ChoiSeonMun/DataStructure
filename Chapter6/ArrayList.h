#pragma once

#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <cstdio>

constexpr int MAX_LIST_SIZE = 100;

class ArrayList {
public:
	ArrayList()
		: data(), length(0) { }

	void	insert(int pos, int item);
	void	remove(int pos);
	int		getEntry(int pos);
	bool	isEmpty() { return length == 0; }
	bool	isFull() { return length == MAX_LIST_SIZE; }
	bool	find(int item);
	void	replace(int pos, int item);
	int		size() { return length; }
	void	display();
	void	clear() { length = 0; }
private:
	int		data[MAX_LIST_SIZE];
	int		length;
};

//Feature : to insert item into pos
void ArrayList::insert(int pos, int item)
{
	if (isFull())
	{
		puts("this list is full");
		return;
	}
	else if (pos >= MAX_LIST_SIZE)
	{
		puts("invaild position");
		return;
	}

	for (int i = length; i > pos; --i)
		data[i] = data[i - 1];
	data[pos] = item;
	++length;
}

//Feature : to remove an item at pos from list
void ArrayList::remove(int pos)
{
	if (isEmpty())
	{
		puts("this list is empty");
		return;
	}
	else if (pos >= MAX_LIST_SIZE)
	{
		puts("invaild position");
		return;
	}

	for (int i = pos; i < length; ++i)
		data[i] = data[i + 1];
	--length;
}

//Feature : to get an item at pos
//Return : if the position is invaild or the list is empty, return -1
//			or, return item
int ArrayList::getEntry(int pos)
{
	if (isEmpty())
	{
		puts("this list is empty");
		return -1;
	}
	else if (pos >= MAX_LIST_SIZE)
	{
		puts("invaild position");
		return -1;
	}

	return data[pos];
}

//Feature : to find the item in list
//Return : if the list is empty or there isn't the item, return false. or, return true
bool ArrayList::find(int item)
{
	if (isEmpty())
		return false;

	for (int i = 0; i != length; ++i)
	{
		if (data[i] == item)
			return true;
	}

	return false;
}

//Feature : to replace an item at pos with the item
void ArrayList::replace(int pos, int item)
{
	if (isEmpty())
	{
		puts("this list is empty");
		return;
	}
	else if (pos >= MAX_LIST_SIZE)
	{
		puts("invalid value");
		return;
	}

	data[pos] = item;
}

//Feature : to display items in the list
void ArrayList::display()
{
	printf("[the number of items in the list implemented array = %2d] : ", length);
	for (int i = 0; i < length; ++i)
		printf("[%2d] ", data[i]);
	printf("\n");
}
#endif