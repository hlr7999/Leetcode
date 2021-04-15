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
    int minCameraCover(TreeNode* root) {
        return dfs(root) == 0 ? res + 1 : res;
    }
    // Greedy Algorithm
    // 0 means the node is not covered
    // 1 means the node is covered but no camera here
    // 2 means the there is a camera in this node
    int dfs(TreeNode* node) {
        if (!node) return 1;
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 0 || right == 0) {
            ++res;
            return 2;
        }
        if (left == 1 && right == 1) {
            return 0;
        }
        return 1;
    }
private:
    int res = 0;
};