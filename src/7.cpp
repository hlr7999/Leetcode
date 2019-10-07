#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int tail = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && tail > 7))
                return 0;
            if (res < INT_MIN/10 || (res == INT_MIN/10 && tail < -8))
                return 0;
            res = res * 10 + tail;
        }
        return res;
    }
};