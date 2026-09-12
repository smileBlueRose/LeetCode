long long eatingSpeed(int* piles, int size, int k)
{
    if (k <= 0)
        return -1;

    long long result = 0;
    for (int i = 0; i < size; i++) {
        result += piles[i] / k + (int)(piles[i] % k != 0);
    }
    return result;
}

int minEatingSpeed(int* piles, int size, int h)
{
    int left = 1;
    int right = -1;
    for (int i = 0; i < size; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        long long res_h = eatingSpeed(piles, size, mid);
        if (res_h <= h)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return left;
}