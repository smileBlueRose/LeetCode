#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int size)
{
    qsort(nums, size, sizeof(int), compare);
    for (int i = 1; i < size; i++)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}