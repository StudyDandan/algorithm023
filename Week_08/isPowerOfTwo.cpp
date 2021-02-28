bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    int r = n & (n - 1);
    return r == 0;
}