#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                ++count;
                int num = i << 1;
                while (num < n) {
                    is_prime[num] = false;
                    num += i;
                }
            }
        }
        return count;
    }
};