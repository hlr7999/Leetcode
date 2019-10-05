#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // dfs
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 1;
        dfs(root, res);
        return res - 1;
    }
    int dfs(TreeNode* root, int& res) {
        if (root == NULL) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        if (left + right + 1 > res)
            res = left + right + 1;
        return max(left, right) + 1;
    }
};