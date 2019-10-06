#include <vector>
#include <stack>
#include <algorithm>
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
    // find the the first element which is larger than someone on its right
    // find the the first element which is smaller than someone on its left
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2;
        int left_max = nums[0], right_min = nums[n-1];
        for (int i = 1; i < n; ++i) {
            left_max = max(left_max, nums[i]);
            if (nums[i] < left_max)
                end = i;
            int right_i = n-1-i;
            right_min = min(right_min, nums[right_i]);
            if (nums[right_i] > right_min)
                start = right_i;
        }
        return end - start + 1;
    }
};