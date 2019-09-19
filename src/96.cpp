#include <vector>

using namespace std;

class Solution {
public:
    // Dynamic Programming
    int numTrees(int n) {
        vector<int> dp(n+2, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i/2; ++j) {
                dp[i] += dp[j-1] * dp[i-j] * 2;
            }
            if (i % 2) {
                dp[i] += dp[i/2] * dp[i/2];
            }
        }
        return dp[n];
    }
};