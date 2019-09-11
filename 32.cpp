#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int max_len = 0;
        // from left to right
        for (auto& c : s) {
            if (c == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left < right) {
                left = right = 0;
            } else if (left == right) {
                if (left > max_len) {
                    max_len = left;
                }
            }
        }
        // from right to left
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left > right) {
                left = right = 0;
            } else if (left == right) {
                if (left > max_len) {
                    max_len = left;
                }
            }
        }
        return max_len * 2;
    }

    // Dynamic Programming
    int longestValidParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int* dp = new int[s.size()];
        dp[0] = 0;
        int max_len = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i > 1 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + 2 + 
                        (i - dp[i-1] - 1 > 0 ? dp[i - dp[i-1] - 2] : 0);
                } else {
                    dp[i] = 0;
                }
            } else {
                dp[i] = 0;
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
            }
        }
        return max_len;
    }
};