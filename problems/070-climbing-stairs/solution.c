int climbStairs(int n) {
    if (n <= 3)
        return n;

    int result = 0;
    int a = 2, b = 3;

    for (int i = 4; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}