#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // recursive
    bool isSymmetric(TreeNode* root) {
        return recur(root->left, root->right);
    }
    bool recur(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        } else if (!t1 || !t2) {
            return false;
        }
        return (t1->val == t2->val) &&
            recur(t1->left, t2->right) &&
            recur(t1->right, t2->left);
    }
    // queue
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while (!qu.empty()) {
            TreeNode* t1 = qu.front(); qu.pop();
            TreeNode* t2 = qu.front(); qu.pop();
            if (!t1 && !t2) {
                continue;
            } else if (!t1 || !t2) {
                return false;
            } else if (t1->val != t2->val) {
                return false;
            }
            qu.push(t1->left); qu.push(t2->right);
            qu.push(t1->right); qu.push(t2->left);
        }
        return true;
    }
};