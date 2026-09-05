int lower_bound(int* nums, int nums_size, int target)
{
    int left = 0;
    int right = nums_size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            if (mid > 0 && nums[mid - 1] == target) {
                right = mid - 1;
            } 
            else
                return mid;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int upper_bound(int* nums, int nums_size, int target)
{
    int left = 0;
    int right = nums_size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            if (mid < nums_size - 1 && nums[mid + 1] == target) {
                left = mid + 1;
            } 
            else
                return mid;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int* searchRange(int* nums, int nums_size, int target, int* return_size)
{
    int* result = malloc(sizeof(int) * 2);
    *return_size = 2;
    result[0] = lower_bound(nums, nums_size, target);
    result[1] = upper_bound(nums, nums_size, target);
    return result;
}