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
    // No recursive
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* left = root->left;
                while(left->right) {
                    left = left->right;
                }
                left->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};