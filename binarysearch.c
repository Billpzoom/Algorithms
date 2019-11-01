#include <stdio.h>

int BinarySearch(int key, int array[], int len)
{
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (key < array[middle]) high = middle - 1;
        else if(key > array[middle]) low = middle + 1;
        else return middle;
    }
    return -1;
}