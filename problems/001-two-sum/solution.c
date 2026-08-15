#include <stdio.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] + nums[j] == target && i != j) {
                int* result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }

    return NULL;
}