#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    // dynamic programming or merging
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0 || n == 0) {
            return 0;
        }
        if (2*k > n) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                res += max(0, prices[i] - prices[i-1]);
            }
            return res;
        }
        vector<vector<int>> dp(k+1, vector<int>(2, INT_MIN));
        dp[0][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                if (j > 0) {
                    dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= k; ++j) {
            if (dp[j][0] > res) res = dp[j][0];
        }
        return res;
    }
};