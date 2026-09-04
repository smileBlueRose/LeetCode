int trap(int* height, int size)
{
    int total = 0;
    int lmax_arr[size];
    int rmax_arr[size];

    int lmax = 0;
    for (int i = 0; i < size; i++) {
        if (height[i] > lmax) {
            lmax = height[i];
        }
        lmax_arr[i] = lmax;
    }
    int rmax = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (height[i] > rmax) {
            rmax = height[i];
        }
        rmax_arr[i] = rmax;
    }

    for (int i = 0; i < size; i++) {
        lmax = lmax_arr[i];
        rmax = rmax_arr[i];

        if (lmax > 0 && rmax > 0) {
            int min_side = lmax < rmax ? lmax : rmax;
            if (min_side > height[i])
                total += min_side - height[i];
        }
    }

    return total;
}