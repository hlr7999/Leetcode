#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (!s.empty()) {
            s.erase(0, s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }
        bool numSeen = false;
        bool pointSeen = false;
        bool eSeen = false;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if ('0' <= c && c <= '9') {
                numSeen = true;
            } else if (c == '.') {
                if (eSeen || pointSeen) {
                    return false;
                }
                pointSeen = true;
            } else if (c == 'e') {
                if (eSeen || !numSeen) {
                    return false;
                }
                numSeen = false;
                eSeen = true;
            } else if (c == '-' || c == '+') {
                if (i != 0 && s[i-1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return numSeen;
    }
};