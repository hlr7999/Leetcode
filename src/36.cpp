#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_has[9][9] = {0}, col_has[9][9] = {0}, cell_has[9][9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int c = i / 3 * 3 + j / 3;
                    if (row_has[i][num] || col_has[j][num] || cell_has[c][num])
                        return false;
                    row_has[i][num] = col_has[j][num] = cell_has[c][num] = 1;
                }
            }
        }
        return true;
    }
};