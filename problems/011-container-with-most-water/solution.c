int maxArea(int* arr, int size)
{
    int max_area = 0;
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int a = (right - left) * (arr[left] < arr[right] ? arr[left] : arr[right]);
        
        if (a > max_area)
            max_area = a;
        
        if (arr[left] < arr[right])
            left++;
        else
            right--;
    }

    return max_area;
}