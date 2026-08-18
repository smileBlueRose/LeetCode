int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int *result = malloc(sizeof(int) * (digitsSize + 1));
    char carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9 && carry) {
            result[i] = 0;
            if (i == 0) {
                result[0] = 1;
                result[digitsSize] = 0;
                *returnSize = digitsSize + 1;
                return result;
            }
        }
        else {
            result[i] = digits[i] + carry;
            if (carry) carry--;
        }
    }
    *returnSize = digitsSize;
    return result;
}
