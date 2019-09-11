#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int s_len = s.size(), p_len = p.size();
    vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
    dp[s_len][p_len] = true;
    for (int i = s_len; i >= 0; --i) {
        for (int j = p_len - 1; j >= 0; --j) {
            bool first_match = (i < s_len && (s[i] == p[j] || p[j] == '.'));
            if (j < p_len - 1 && p[j+1] == '*') {
                dp[i][j] = (dp[i][j+2] || (first_match && dp[i+1][j]));
            } else {
                dp[i][j] = (first_match && dp[i+1][j+1]);
            }
        }
    }
    return dp[0][0];
};

int main() {

}