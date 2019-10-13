#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;
    vector<vector<string>> res;

public:
    // dp + dfs
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        // dp
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && (dp[i+1][j-1] || j == i + 1))
                    dp[i][j] = true;
            }
        }
        // dfs
        vector<string> temp;
        dfs(temp, s, 0);
        return res;
    }
    void dfs(vector<string>& temp, string& s, int start) {
        if (start == s.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (dp[start][i]) {
                temp.push_back(s.substr(start, i - start + 1));
                dfs(temp, s, i + 1);
                temp.pop_back();
            }
        }
    }
};