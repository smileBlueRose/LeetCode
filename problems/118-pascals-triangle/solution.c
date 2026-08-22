int** generate(int num_rows, int* return_size, int** return_column_sizes)
{
    int **result = (int**)malloc(num_rows * sizeof(int*));
    *return_column_sizes = (int*)malloc(num_rows * sizeof(int));
    *return_size = num_rows;

    for (int i = 0; i < num_rows; i++) {
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*return_column_sizes)[i] = i + 1;

        result[i][0] = 1;
        result[i][i] = 1;
        
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
    }
    return result;
}
