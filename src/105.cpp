#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> in_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size()-1, preorder, inorder);
    }
    TreeNode* recur(int pre_start, int in_start, int in_end, vector<int>& preorder, vector<int>& inorder) {
        if (pre_start >= preorder.size() || in_start > in_end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_index = in_map[preorder[pre_start]];
        root->left = recur(pre_start+1, in_start, in_index-1, preorder, inorder);
        root->right = recur(pre_start+in_index-in_start+1, in_index+1, in_end, preorder, inorder);
        return root;
    }
};