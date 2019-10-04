#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return recur(s, index);
    }
    string recur(const string& s, int& index) {
        string res;
        while (index < s.size() && s[index] != ']') {
            int n = 0;
            while (isdigit(s[index]))
                n = n*10 + s[index++]-'0';
            if (n > 0) {
                string temp = recur(s, ++index);
                for (int i = 0; i < n; ++i)
                    res += temp;
            } else res += s[index];
            ++index;
        }
        return res;
    }
};