int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int *result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int *suffix = malloc((numsSize + 1) * sizeof(int));
    suffix[numsSize] = 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i];
    }

    int prefix = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = prefix * suffix[i + 1];
        prefix *= nums[i];
    }

    free(suffix);
    return result;
}