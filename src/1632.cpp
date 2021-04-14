#include <vector>
#include <map>
#include <numeric>

using namespace std;

class Solution {
public:
    // Sort & Union Find
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        // auto sort
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[matrix[i][j]].push_back({i, j});
            }
        }
        // store max rank of each row and col
        vector<int> max_rank(m + n, 0);
        for (auto& it : mp) {
            vector<int> fa(m + n);
            iota(fa.begin(), fa.end(), 0);
            vector<int> temp_max_rank = max_rank;
            for (auto& c : it.second) {
                int i = find(fa, c.first), j = find(fa, c.second + m);
                fa[i] = j;
                temp_max_rank[j] = max(temp_max_rank[i], temp_max_rank[j]);
            }
            for (auto& c : it.second) {
                int rank = temp_max_rank[find(fa, c.first)] + 1;
                res[c.first][c.second] = rank;
                max_rank[c.first] = max_rank[c.second + m] = rank;
            }
        }
        return res;
    }

    int find(vector<int>& fa, int x) {
        return x == fa[x] ? x : (fa[x] = find(fa, fa[x]));
    }
};