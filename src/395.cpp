#include <string>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        for (int unique_char = 1; unique_char < 27; ++unique_char) {
            int mp[128] = {0};
            int begin = 0, end = 0;
            int cur_unique_char = 0;
            int cur_char_gt_k = 0;
            while (end < n) {
                if (mp[s[end]]++ == 0)
                    ++cur_unique_char;
                if (mp[s[end++]] == k)
                    ++cur_char_gt_k;
                while (cur_unique_char > unique_char) {
                    if (mp[s[begin]]-- == k)
                        --cur_char_gt_k;
                    if (mp[s[begin++]] == 0)
                        --cur_unique_char;
                }
                if (cur_char_gt_k == unique_char && end - begin > res) {
                    res = end - begin;
                }
            }
        }
        return res;
    }
};