#include <queue>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode* node = qu.front(); qu.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) qu.push(node->left);
            if (node->right) qu.push(node->right);
        }
        return root;
    }
};