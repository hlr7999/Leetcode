#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root) {
            rec(result, root);
        }
        return result;
    }
    void rec(vector<int>& result, TreeNode* node) {
        if (node->left) {
            rec(result, node->left);
        }
        result.push_back(node->val);
        if (node->right) {
            rec(result, node->right);
        }
    }
};