#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (!isalnum(s[lo]))
                ++lo;
            else if (!isalnum(s[hi]))
                --hi;
            else if (tolower(s[lo]) != tolower(s[hi]))
                return false;
            else {++lo; --hi;}
        }
        return true;
    }
};