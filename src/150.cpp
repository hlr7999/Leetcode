#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1, num2;
        for (string str : tokens) {
            if (str == "+") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                st.push(num1 + num2);
            } else if (str == "-") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                st.push(num2 - num1);
            } else if (str == "*") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                st.push(num1 * num2);
            } else if (str == "/") {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();
                st.push(num2 / num1);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};