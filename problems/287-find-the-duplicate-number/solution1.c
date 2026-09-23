#include <stdbool.h>


int findDuplicate(int* nums, int numsSize)
{
    bool digits[100001] = {0};
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        if (digits[n] == true)
            return n;
        digits[n] = true;
    }
    
    return -1;
}