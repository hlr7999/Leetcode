#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int end = 0, start = 0;
        int n = s.size();
        vector<int> mp(128, 0);
        for (char c : p) {
            ++mp[c];
        }
        int p_size = p.size();
        int counter = p_size;
        vector<int> res;
        while (end < n) {
            if (mp[s[end]] > 0) {
                --counter;
            }
            --mp[s[end]];
            ++end;
            while (counter == 0) {
                if (mp[s[start]] == 0) {
                    if (end - start == p_size) {
                        res.push_back(start);
                    }
                    ++counter;
                }
                ++mp[s[start]];
                ++start;
            }
        }
        return res;
    }
};