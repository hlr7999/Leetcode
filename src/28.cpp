#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;
        vector<int> next = kmpGetNext(needle);
        for (int i = 0, j = 0; i < m;) {
            if (j == -1 || haystack[i] == needle[j]) { 
                ++i, ++j;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j = next[j];
            }
        }
        return -1;
    }
    vector<int> kmpGetNext(string p) {
        int pLen = p.size();
        vector<int> next(pLen);
        next[0] = -1;
        int k = -1, j = 0;
        while (j < pLen - 1) {
            if (k == -1 || p[j] == p[k])
                next[++j] = ++k;
            else
                k = next[k];
        }
        return next;
    }
};