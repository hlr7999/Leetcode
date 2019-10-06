#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // dp
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n,vector<bool>(n, false));
        int count = n;
        for (int i = n - 1; i >= 0; --i) {
            isPal[i][i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && (isPal[i+1][j-1] || j == i + 1)) {
                    isPal[i][j] = true;
                    ++count;
                }
            }
        }
        return count;
    }
    // expand around center
    int countSubstrings(string s) {
        int n = s.size();
        int count = n;
        for(int i = 0; i < n; ++i)
        {
            int lo = i-1, hi = i+1;
            while(lo >= 0 && hi < n && s[lo] == s[hi]) {
                ++count; --lo; ++hi;
            }
            lo = i, hi = i+1;
            while(lo >= 0 && hi < n && s[lo] == s[hi]) {
                ++count; --lo; ++hi;
            }
        }
        return count;
    }
};