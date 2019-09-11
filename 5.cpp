#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dynamic Programming
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> isPal(n,vector<bool>(n, false));
    int left = 0, len = 0;
    for (int i = n - 1; i >= 0; --i) {
        isPal[i][i] = true;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j] && (isPal[i+1][j-1] || j == i + 1)) {
                isPal[i][j] = true;
                if (j - i > len) {
                    len = j - i;
                    left = i;
                }
            }
        }
    }
    return s.substr(left, len + 1);
}

// Manacher's Algorithm 马拉车算法
string longestPalindrome(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
    
}