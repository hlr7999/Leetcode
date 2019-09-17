#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // DFS
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if (board[x][y] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        // visited
        board[x][y] ^= 128;
        if (dfs(board, word, x-1, y, index+1) || dfs(board, word, x+1, y, index+1)
            || dfs(board, word, x, y-1, index+1) || dfs(board, word, x, y+1, index+1)) {
            return true;
        }
        board[x][y] ^= 128;
        return false;
    }
};