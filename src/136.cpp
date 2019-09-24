#include <vector>

using namespace std;

class Solution {
public:
    // xor !!!!!!
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            ans ^= i;
        }
        return ans;
    }
};