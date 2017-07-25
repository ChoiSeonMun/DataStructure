#pragma once

#ifndef Utility_H
#define Utility_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

void initRandom(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i != size; ++i)
        arr[i] = rand() % 100;
}

void printArray(int arr[], int size)
{
    puts("Elements in array");
    puts("---------------------");
    for (int i = 0; i != size; ++i)
        printf("%d ", arr[i]);
    puts("");
}
#endif