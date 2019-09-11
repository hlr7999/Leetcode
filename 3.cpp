#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLen = -1;
    int lastPos[256] = {0}, leftPos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (lastPos[s[i]] == 0 || lastPos[s[i]] <= leftPos) {
            int len = i + 1 - leftPos;
            maxLen = maxLen < len ? len : maxLen;
        } else {
            leftPos = lastPos[s[i]];
        }
        lastPos[s[i]] = i + 1;
    }

    return maxLen;
};

int main() {
    string a = "abcabcd";
    cout << lengthOfLongestSubstring(a);

    return 0;
}