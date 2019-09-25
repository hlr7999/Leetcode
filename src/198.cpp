#include <vector>
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
    // Dynamic programming
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int* dp = new int[n+1];
        dp[0] = 0; dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        return dp[n];
    }
};