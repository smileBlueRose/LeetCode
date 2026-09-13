int findMinIndex(int* nums, int size)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == nums[right])
            return mid;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return -1;
}

int search(int* nums, int size, int target)
{
    int min_index = findMinIndex(nums, size);
    int left, right;
    if (min_index == 0) {
        left = 0;
        right = size - 1;
    }
    else if (nums[min_index] <= target && target <= nums[size - 1]) {
        left = min_index;
        right = size - 1;
    }
    else if (nums[0] <= target && target <= nums[min_index - 1]) {
        left = 0;
        right = min_index - 1;
    }
    else {
        return -1;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}