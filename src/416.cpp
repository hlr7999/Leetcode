#include <vector>

using namespace std;

class Solution {
public:
    // 0/1 knapsack
    // dp[i][j] = dp[i-1][j] || dp[i-1][j-num[i-1]]
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum & 1 == 1)
            return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= nums[i-1])
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[sum];
    }
};