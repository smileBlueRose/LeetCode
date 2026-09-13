int findMin(int* nums, int size)
{
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (nums[mid] == nums[right])
            break;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[mid];
}