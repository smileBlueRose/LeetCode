#include <stdlib.h>


int* twoSum(int* numbers, int number_size, int target, int* return_size)
{
    int* res = calloc(2, sizeof(int));
    if (res == NULL)
        return NULL;

    int left = 0;
    int right = number_size - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            res[0] = left + 1;
            res[1] = right + 1;
            *return_size = 2;
            return res;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    *return_size = 0;
    return res;
}