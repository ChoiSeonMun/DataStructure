#pragma once

#ifndef Sort_H
#define Sort_H

#include <algorithm>
#include <memory.h>
#include "CircularQueue.h"

static constexpr int BUCKETS = 10;
static constexpr int DIGITS = 4;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i != size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j != size; ++j)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}

inline int ascend(int x, int y) { return y - x; }
inline int decend(int x, int y) { return x - y; }
void insertionSort(int arr[], int size, int (*func)(int, int))
{
    for (int i = 1; i != size; ++i)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && func(arr[j], key) < 0; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

static void sortGapInsertion(int arr[], int first, int last, int gap)
{
    int min, j;
    for (int i = first + gap; i <= last; i += gap)
    {
        min = arr[i];
        for (j = i - gap; j >= first && arr[j] > min; j -= gap)
                arr[j + gap] = arr[j];
        arr[j] = min;
    }
}

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        if (!(gap % 2))
            ++gap;
        for (int i = 0; i < gap; ++i)
            sortGapInsertion(arr, i, size - 1, gap);
    }
}

static void merge(int arr[], int left, int mid, int right)
{
    static constexpr int MAX_SIZE = 1024;
    int leftPointer = left, rightPointer = mid + 1;
    static int sorted[MAX_SIZE];
    int idx = left;
    while (leftPointer <= mid && rightPointer <= right)
            sorted[idx++] = (arr[leftPointer] <= arr[rightPointer]) ? arr[leftPointer++] : arr[rightPointer++];

    if (leftPointer > mid)
    {
        while (rightPointer <= right)
            sorted[idx++] = arr[rightPointer++];
    }
    else
    {
        while (leftPointer <= mid)
            sorted[idx++] = arr[leftPointer++];
    }
    for (int i = left; i <= right; ++i)
        arr[i] = sorted[i];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

static int partition(int arr[], int left, int right)
{
    int pivot = left;
    int low = pivot;
    int high = right + 1;
    do {
        do {
            ++low;
        } while (low <= right && arr[low] < arr[pivot]);
        do {
            --high;
        } while (high >= left && arr[high] > arr[pivot]);
        if (low < high)
            std::swap(arr[low], arr[high]);
    } while (low < high);
    std::swap(arr[pivot], arr[high]);

    return high;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

void radixSort(int arr[], int size)
{
    CircularQueue queues[BUCKETS];
    int factor = 1;
    for (int d = 0; d < DIGITS; ++d)
    {
        for (int i = 0; i < size; ++i)
            queues[(arr[i] / factor) % 10].enqueue(arr[i]);
        int idx = 0;
        for (int b = 0; b < BUCKETS; ++b)
        {
            while (!queues[b].isEmpty())
                arr[idx++] = queues[b].dequeue();
        }
        factor *= 10;
    }
}
#endif