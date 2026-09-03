#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int nums_size, int* return_size, int** return_column_sizes)
{
    *return_size = 0;
    if (nums_size < 3)
        return NULL;

    qsort(nums, nums_size, sizeof(int), comp);

    size_t max_triplets = (size_t)nums_size * (nums_size - 1) / 2;
    int** temp_result = malloc(sizeof(int*) * max_triplets);

    for (int i = 0; i < nums_size - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums_size - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                temp_result[*return_size] = malloc(sizeof(int) * 3);
                temp_result[*return_size][0] = nums[i];
                temp_result[*return_size][1] = nums[left];
                temp_result[*return_size][2] = nums[right];

                (*return_size)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }

    int** result = malloc(sizeof(int*) * (*return_size));
    *return_column_sizes = malloc(sizeof(int) * (*return_size));

    for (int i = 0; i < *return_size; i++) {
        result[i] = temp_result[i];
        (*return_column_sizes)[i] = 3;
    }

    free(temp_result);

    return result;
}