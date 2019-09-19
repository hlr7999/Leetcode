#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // for each bar, find the maximal area that contains the bar
    // and find the maximal of these maximal areas
    // to find the maximal area, we find the first bar that
    // less then the current bar on the right and left
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int cur = 0;
        int max_area = 0;
        while (cur < heights.size()) {
            if (st.empty()) {
                st.push(cur);
                ++cur;
            } else if (heights[cur] >= heights[st.top()]) {
                st.push(cur);
                ++cur;
            } else {
                int top_height = heights[st.top()];
                st.pop();
                int left_less = st.empty() ? -1 : st.top();
                int area = (cur - left_less - 1) * top_height;
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        while (!st.empty()) {
            int top_height = heights[st.top()];
            st.pop();
            int left_less = st.empty() ? -1 : st.top();
            int area = (cur - left_less - 1) * top_height;
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};