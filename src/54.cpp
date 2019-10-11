#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        vector<int> res;
        int row_beg = 0, row_end = m - 1;
        int col_beg = 0, col_end = matrix[0].size() - 1;
        while (row_beg <= row_end && col_beg <= col_end) {
            // left -> right
            for (int i = col_beg; i <= col_end; ++i)
                res.push_back(matrix[row_beg][i]);
            ++row_beg;
            // top -> bottom
            for (int i = row_beg; i <= row_end; ++i)
                res.push_back(matrix[i][col_end]);
            --col_end;
            // right -> left
            if (row_beg <= row_end) {
                for (int i = col_end; i >= col_beg; --i)
                    res.push_back(matrix[row_end][i]);
                --row_end;
            }
            // bottom -> top
            if (col_beg <= col_end) {
                for (int i = row_end; i >= row_beg; --i)
                    res.push_back(matrix[i][col_beg]);
                ++col_beg;
            }
        }
        return res;
    }
};