int* get_row(int row_index, int* return_size) 
{
    *return_size = row_index + 1;
    int *res = malloc(sizeof(int) * *return_size);

    res[0] = 1;
    for (int i = 1; i < *return_size; i++)
        res[i] = (long int)res[i-1] * (long int)(row_index - i + 1) / i;

    return res;
}