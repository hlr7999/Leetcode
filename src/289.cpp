#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = liveNeighbors(board, i, j);
                if (board[i][j] && (live == 2 || live == 3)) {
                    board[i][j] = 3;
                } else if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
private:
    int m, n;
    int liveNeighbors(vector<vector<int>>& board, int x, int y) {
        int res = 0;
        for (int i = max(0, x-1); i < min(m, x+2); ++i) {
            for (int j = max(0, y-1); j < min(n, y+2); ++j) {
                res += board[i][j] & 1;
            }
        }
        return res - board[x][y] & 1;
    }
};