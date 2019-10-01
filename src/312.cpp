#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // dp
    int maxCoins(vector<int>& nums) {
        // burst zero
        vector<int> balloons(nums.size() + 2);
        int n = 1;
        for (int num : nums) {
            if (num > 0) balloons[n++] = num;
        }
        balloons[0] = balloons[n++] = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int interval = 2; interval < n; ++interval) {
            for (int left = 0; left < n - interval; ++left) {
                int right = left + interval;
                int max_cur = 0;
                for (int i = left + 1; i < right; ++i) {
                    max_cur = max(max_cur, balloons[left]*balloons[i]*balloons[right]
                        + dp[left][i] + dp[i][right]);
                }
                dp[left][right] = max_cur;
            }
        }
        return dp[0][n-1];
    }
};