#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<int> nums;
        int num = 0, pre;
        char op = '+';
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i]))
                num = num*10 + s[i] - '0';
            if ((s[i] != ' ' && !isdigit(s[i])) || i == len-1) {
                switch (op) {
                case '-':
                    nums.push(-num); break;
                case '+':
                    nums.push(num); break;
                case '*':
                    pre = nums.top(); nums.pop();
                    nums.push(pre*num); break;
                case '/':
                    pre = nums.top(); nums.pop();
                    nums.push(pre/num); break;
                }
                op = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (nums.size() > 0) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};