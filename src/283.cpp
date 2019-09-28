#include <vector>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_not_zero = 0;
        for (int num : nums) {
            if (num) nums[last_not_zero++] = num;
        }
        for (int i = last_not_zero; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};