#include "Sort.h"
#include "Utility.h"

int main()
{
    int arr[10];
    initRandom(arr, 10);
    printArray(arr, 10);
    insertionSort(arr, 10, ascend);
    printArray(arr, 10);
    insertionSort(arr, 10, decend);
    printArray(arr, 10);

    return 0;
}