#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // dp
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        if (s[n-1] != '0') dp[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            if (s[i] != '0') {
                dp[i] = dp[i+1];
                int num = (s[i] - '0') * 10 + s[i+1] - '0';
                if (num < 27)
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};