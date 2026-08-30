#include <stdbool.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    for (int row = 0; row < 9; row++) {
        int numbers[9] = {0};
        for (int i = 0; i < 9; i++) {
            char symbol = board[row][i];
            if (symbol == '.')
                continue;

            int cell = symbol - '1';
            if (numbers[cell] != 0)
                return false;
            numbers[cell] = 1;
        }
    }

    for (int col = 0; col < 9; col++) {
        int numbers[9] = {0};
        for (int i = 0; i < 9; i++) {
            char symbol = board[i][col];
            if (symbol == '.')
                continue;

            int cell = symbol - '1';
            if (numbers[cell] != 0)
                return false;
            numbers[cell] = 1;
        }
    }

    int box_centers[9][2] = {
        {1, 1}, {4, 1}, {7, 1},
        {1, 4}, {4, 4}, {7, 4},
        {1, 7}, {4, 7}, {7, 7}
    };
    for (int box = 0; box < 9; box++) {
        int c1 = box_centers[box][0];
        int c2 = box_centers[box][1];
        int numbers[9] = {0};

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                char symbol = board[c1 + i][c2 + j];
                if (symbol == '.')
                    continue;

                int cell = symbol - '1';
                if (numbers[cell] != 0)
                    return false;
                numbers[cell] = 1;
            }
        }

    }
    return true;
}