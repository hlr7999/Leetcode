#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    string word;
    TrieNode* children[26];
    TrieNode() : word("") {
        memset(children, 0, sizeof(TrieNode*)*26);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if (m == 0) return {};
        n = board[0].size();
        TrieNode* root = buildTrie(words);
        vector<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, res, root);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y, vector<string>& res, TrieNode* root) {
        char c = board[x][y];
        if (c == '#' || root->children[c - 'a'] == NULL)
            return;
        root = root->children[c - 'a'];
        if (root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        // visited
        board[x][y] = '#';
        if (x > 0) dfs(board, x-1, y, res, root);
        if (y > 0) dfs(board, x, y-1, res, root);
        if (x < m-1) dfs(board, x+1, y, res, root);
        if (y < n-1) dfs(board, x, y+1, res, root);
        board[x][y] = c;
    }
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* temp = root;
            for (char c : w) {
                int i = c - 'a';
                if (temp->children[i] == NULL)
                    temp->children[i] = new TrieNode();
                temp = temp->children[i];
            }
            temp->word = w;
        }
        return root;
    }
    int m, n;
};