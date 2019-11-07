#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int row_beg = 0, row_end = n - 1;
        int col_beg = 0, col_end = n - 1;
        int count = 1;
        while (row_beg <= row_end && col_beg <= col_end) {
            // left -> right
            for (int i = col_beg; i <= col_end; ++i)
                matrix[row_beg][i] = count++;
            ++row_beg;
            // top -> bottom
            for (int i = row_beg; i <= row_end; ++i)
                matrix[i][col_end] = count++;
            --col_end;
            // right -> left
            if (row_beg <= row_end) {
                for (int i = col_end; i >= col_beg; --i)
                   matrix[row_end][i] = count++;
                --row_end;
            }
            // bottom -> top
            if (col_beg <= col_end) {
                for (int i = row_end; i >= row_beg; --i)
                    matrix[i][col_beg] = count++;
                ++col_beg;
            }
        }
        return matrix;
    }
};