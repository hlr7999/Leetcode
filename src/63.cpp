#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int width = obstacleGrid[0].size();
        vector<int> dp(width, 0);
        dp[0] = 1;
        for (auto& row : obstacleGrid) {
            if (row[0] == 1) dp[0] = 0;
            for (int j = 1; j < width; ++j) {
                if (row[j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[width - 1];
    }
};