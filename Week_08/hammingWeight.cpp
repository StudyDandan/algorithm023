#include <cstdint>

int hammingWeight(uint32_t n) {
    //±©Á¦½â·¨
    int size = 0;
    while (n) {
        if (n & 1)size++;
        n = n >> 1;
    }
    return size;
}