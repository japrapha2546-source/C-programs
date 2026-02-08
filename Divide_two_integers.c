int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    long long a = dividend < 0 ? -(long long)dividend : dividend;
    long long b = divisor < 0 ? -(long long)divisor : divisor;

    long long result = 0;

    while (a >= b) {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        result += multiple;
    }
    if ((dividend < 0) ^ (divisor < 0))
        result = -result;
    if (result > 2147483647) 
        return 2147483647;
    if (result < -2147483648)
        return -2147483648;
    return (int)result;
}
