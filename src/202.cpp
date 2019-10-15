#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (set.insert(n).second) {
            int sum = 0;
            while (n > 0) {
                int remain = n%10;
                sum += remain*remain;
                n /= 10;
            }
            if (sum == 1)
                return true;
            else
                n = sum;
        }
        return false;
    }
};