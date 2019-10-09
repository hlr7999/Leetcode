#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) return INT_MIN;
            else return divisor&1 ? divide(dividend+1, divisor) : divide(dividend>>1, divisor>>1);
        }
        if (divisor == INT_MIN) return 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ans = 0;
        while (dividend >= divisor) {
            int temp = divisor, count = 1;
            while (temp << 1 > 0 && temp << 1 <= dividend) {
                temp <<= 1;
                count <<= 1;
            }
            ans += count;
            dividend -= temp;
        }
        return sign * ans;
    }
};