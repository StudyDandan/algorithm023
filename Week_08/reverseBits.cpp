#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    //ʱ�临�Ӷ�O��1��
    //32λ������λ power=31
    //����ȡ��Ԫ�أ�ֱ��n=0���˳�n&1,n>>1
    //��ϳɶ����ƣ�result += 2^power,����Ӧ�øĳ�<<power
    uint32_t power = 31;
    uint32_t bit = 0;
    uint32_t result = 0;
    //ȡ��Ԫ��
    while (n != 0) {
        bit = (n & 1) << power;
        n = n >> 1;
        result += bit;
        --power;
    }
    return result;
}