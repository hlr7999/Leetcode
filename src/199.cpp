#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(res, root, 1);
        return res;
    }

    void dfs(vector<int>& res, TreeNode* root, int level) {
        if (!root) return;
        if (level > res.size()) {
            res.push_back(root->val);
        }
        dfs(res, root->right, level+1);
        dfs(res, root->left, level+1);
    }
};