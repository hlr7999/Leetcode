#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int max_sum;
    // recursive
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        recur(root);
        return max_sum;
    }
    int recur(TreeNode* root) {
        if (!root) return 0;
        int left = recur(root->left);
        if (left < 0) left = 0;
        int right = recur(root->right);
        if (right < 0) right = 0;
        if (left + right + root->val > max_sum)
            max_sum = left + right + root->val;
        if (left > right)
            return left + root->val;
        else
            return right + root->val;
    }
};