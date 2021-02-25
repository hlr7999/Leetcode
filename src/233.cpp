class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            res += n / divider * i;
            if (n % divider >= 2*i) {
                res += i;
            } else if (n % divider >= i) {
                res += n % i + 1;
            }
        }
        return res;
    }
};