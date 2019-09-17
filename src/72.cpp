#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dynamic Programming
    // dp[i][j] means the minimum steps that
    // covert word1[0,..,i) to word[0,...,j)
    // if word1[i-1] = word2[j-1] then dp[i][j] = dp[i-1][j-1]
    // else there are three conditions
    // 1. replace word1[i-1] by word2[j-1], dp[i][j] = dp[i-1][j-1] + 1
    // 2. if we know dp[i-1][j], then delete word1[i-1]
    // 3. if we know dp[i][j-1], then insert word2[j-1]
    // so dp = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
    // to optimize the space complexity, we only use a vector
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int* dp = new int[n + 1];
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            // to record the pre num
            // pre = dp[i-1][j-1]
            // dp[j-1] = dp[i][j-1]
            // dp[j] = dp[i-1][j]
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = pre;
                } else {
                    dp[j] = min(pre, min(dp[j-1], dp[j])) + 1;
                }
                pre = temp;
            }
        }
        return dp[n];
    }
};