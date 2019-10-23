#include <string>
#include <iostream>

using namespace std;

static int __ = []() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26], last_index[26];
        memset(freq, 0, 26*sizeof(int));
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i]-'a'];
            last_index[s[i]-'a'] = i;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 1 && last_index[i] < res) {
                res = last_index[i];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};