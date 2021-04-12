#include <vector>

using namespace std;

// https://leetcode.com/problems/super-egg-drop/solution/
// dynamic programming
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k, vector<int>(n+1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i < k; ++i) {
            int x = 1;
            for (int j = 1; j <= n; ++j) {
                while (x < j && (max(dp[i-1][x-1], dp[i][j-x]) > max(dp[i-1][x], dp[i][j-x-1])))
                    ++x;
                dp[i][j] = 1 + max(dp[i-1][x-1], dp[i][j-x]);
            }
        }
        return dp[k-1][n];
    }
};