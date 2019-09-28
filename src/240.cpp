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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int x = m-1, y = 0;
        while (x >= 0 && y < n) {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) ++y;
            else --x;
        }
        return false;
    }
};