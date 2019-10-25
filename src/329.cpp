#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m, n;
    int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        if (dp[x][y] != 0) return dp[x][y];
        int max_len = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[x][y]) {
                max_len = max(max_len, 1 + dfs(matrix, dp, nx, ny));
            }
        }
        dp[x][y] = max_len;
        return max_len;
    }
};