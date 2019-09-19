#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // inordee traversal, and the list should be ordered
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        int pre = INT_MIN;
        bool first = true;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (!first && root->val <= pre) {
                return false;
            }
            pre = root->val;
            first = true;
            root = root->right;
        }
        return true;
    }
};