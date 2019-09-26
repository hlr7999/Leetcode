#include <vector>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int n, m;

public:
    // dfs
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++count;
                }
            }
        }
        return count;
    }
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1')
            return;
        grid[x][y] = '0';
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y-1, grid);
        dfs(x, y+1, grid);
    }
};