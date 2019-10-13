#include <vector>

using namespace std;

class Solution {
private:
    int m, n;

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        // row
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[m-1][i] == 'O')
                dfs(board, m-1, i);
        }
        // col
        for (int i = 1; i < m-1; ++i) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;
        board[x][y] = '1';
        dfs(board, x+1, y);
        dfs(board, x-1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }
};