#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dynamic Programming
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = 0;
        unordered_set<string> dict;
        for (string str : wordDict) {
            dict.insert(str);
            if (str.size() > max_len)
                max_len = str.size();
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-1; j >= max(0, i - max_len); --j) {
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};