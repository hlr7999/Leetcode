#include <vector>

using namespace std;

class Solution {
public:
    // dp[i][j] means number of ways to get sum j with first i elements
    // if dp[i-1][j] > 0, then dp[i][j+-nums[i]] += dp[i][j]
    int findTargetSumWays(vector<int>& nums, int S) {
        int all_sum = 0;
        for (int num : nums)
            all_sum += num;
        if (all_sum < S || (all_sum + S) & 1)
            return 0;
        int dp_size = all_sum*2 + 1;
        vector<int> dp(dp_size, 0);
        dp[nums[0] + all_sum] = 1;
        dp[-nums[0] + all_sum] += 1;
        vector<int> next(dp_size);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < dp_size; ++j) {
                if (dp[j] > 0) {
                    next[j + nums[i]] += dp[j];
                    next[j - nums[i]] += dp[j];
                }
            }
            dp = next;
        }
        return dp[S + all_sum];
    }
    // a more excellent solution
    // https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
    int findTargetSumWays(vector<int>& nums, int S) {
        int all_sum = 0;
        for (int num : nums)
            all_sum += num;
        if (all_sum < S || (all_sum + S) & 1)
            return 0;
        int sum = (all_sum + S) >> 1;
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = sum; j >= num; --j) {
                dp[j] += dp[j-num];
            }
        }
        return dp[sum];
    }
};