#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (n != t.size())
            return false;
        int* mp = new int[26];
        memset(mp, 0, sizeof(int)*26);
        for (int i = 0; i < n; ++i)
            ++mp[s[i] - 'a'];
        for (int i = 0; i < n; ++i) {
            if (--mp[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};