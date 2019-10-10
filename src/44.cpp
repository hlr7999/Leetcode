#include <string>

using namespace std;

class Solution {
public:
    // a smarter solution than dp
    bool isMatch(string s, string p) {
        int ss_index, s_index = 0, p_index = 0, star_index = -1;
        while (s_index < s.size()){
            if (p[p_index] == '?' || p[p_index] == s[s_index]) {
                ++s_index; ++p_index; continue;
            } 
            if (p[p_index] == '*') {
                star_index = p_index++; 
                ss_index = s_index;
                continue;
            }
            if (star_index != -1) {
                p_index = star_index + 1;
                s_index = ++ss_index;
                continue;
            } 
            return false;
        }
        while (p_index < p.size() && p[p_index]=='*')
            ++p_index;
        return p_index == p.size();
    }
};