#include <stack>
#include <vector>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // use stack
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res(T.size());
        for (int i = T.size()-1; i >= 0; --i) {
            while (!st.empty() && T[i] >= T[st.top()])
                st.pop();
            if (st.empty()) res[i] = 0;
            else res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};