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
    // inorder
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};