#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dynamic Programming
    // it is a lit difficult, see more in here
    // https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        int max_area = 0;
        
        for (int i = 0; i < m; ++i) {
            int less_left = 0, less_right = n;
            // update height
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }
            // update left
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(less_left, left[j]);
                } else {
                    left[j] = 0;
                    less_left = j + 1;
                }
            }
            // update right
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(less_right, right[j]);
                } else {
                    right[j] = n;
                    less_right = j;
                }
            }

            for (int j = 0; j < n; ++j) {
                int area = (right[j] - left[j]) * height[j];
                if (area > max_area) {
                    max_area = area;
                }
            }
        }

        return max_area;
    }
};