#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0, res = 0, sign = 1;
        for (char& c : s) {
            if (c <= '9' && c >= '0') {
                num = num * 10 + (c - '0');
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                num = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
                num = 0;
            }
        }
        res += sign * num;
        return res;
    }
};