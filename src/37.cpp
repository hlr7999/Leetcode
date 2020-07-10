#include <vector>

using namespace std;

class Solution {
private:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c : getValid(board, i, j)) {
                        board[i][j] = c;
                        if (backtrack(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    vector<char> getValid(vector<vector<char>>& board, int i, int j) {
        vector<char> res;
        int row[9] = {0}, col[9] = {0}, bo[9] = {0};
        int br = i/3*3, bc = j/3*3;
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] != '.')
                row[board[i][k]-'0'-1] = 1;
            if (board[k][j] != '.')
                col[board[k][j]-'0'-1] = 1;
            if (board[br+k/3][bc+k%3] != '.')
                bo[board[br+k/3][bc+k%3]-'0'-1] = 1;
        }
        for (int n = 0; n < 9; ++n) {
            if (row[n] + col[n] + bo[n] == 0) {
                res.push_back('1' + n);
            }
        }
        return res;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};