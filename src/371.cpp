class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        while (b != 0) {
            int carry = (a & b & 0xffffffff) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};