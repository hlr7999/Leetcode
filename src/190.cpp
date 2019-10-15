#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 31; ++i) {
            res += (n&1);
            n >>= 1;
            res <<= 1;
        }
        res += (n&1);
        return res;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = n;
        r = ((r & 0xaaaaaaaa) >> 1) + ((r & 0x55555555) << 1);
        r = ((r & 0xcccccccc) >> 2) + ((r & 0x33333333) << 2);
        r = ((r & 0xf0f0f0f0) >> 4) + ((r & 0x0f0f0f0f) << 4);
        r = ((r & 0xff00ff00) >> 8) + ((r & 0x00ff00ff) << 8);
        r = ((r & 0xffff0000) >> 16) + ((r & 0x0000ffff) << 16);
        return r;
    }
};