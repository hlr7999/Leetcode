#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Two Points to describe the window
    string minWindow(string s, string t) {
        int min_len = INT_MAX, min_start = 0;
        int end = 0, start = 0;
        int n = s.size();
        vector<int> mp(128, 0);
        for (char c : t) {
            ++mp[c];
        }
        int counter = t.size();
        while (end < n) {
            if (mp[s[end]] > 0) {
                --counter;
            }
            --mp[s[end]];
            ++end;
            while (counter == 0) {
                if (mp[s[start]] == 0) {
                    if (end - start < min_len) {
                        min_start = start;
                        min_len = end - start;
                    }
                    ++counter;
                }
                ++mp[s[start]];
                ++start;
            }
        }
        if (min_len != INT_MAX) {
            return s.substr(min_start, min_len);
        }
        return "";
    }
};