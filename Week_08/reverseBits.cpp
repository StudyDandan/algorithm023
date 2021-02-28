#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    //时间复杂度O（1）
    //32位二进制位 power=31
    //依次取出元素，直到n=0，退出n&1,n>>1
    //组合成二进制，result += 2^power,这里应该改成<<power
    uint32_t power = 31;
    uint32_t bit = 0;
    uint32_t result = 0;
    //取出元素
    while (n != 0) {
        bit = (n & 1) << power;
        n = n >> 1;
        result += bit;
        --power;
    }
    return result;
}