#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left_to_right = true;
        vector<vector<int>> res;
        while (!dq.empty()) {
            vector<int> temp;
            int size = dq.size();
            while (size--) {
                if (left_to_right) {
                    root = dq.front(); dq.pop_front();
                    temp.push_back(root->val);
                    if (root->left) dq.push_back(root->left);
                    if (root->right) dq.push_back(root->right);
                } else {
                    root = dq.back(); dq.pop_back();
                    temp.push_back(root->val);
                    if (root->right) dq.push_front(root->right);
                    if (root->left) dq.push_front(root->left);
                }
            }
            left_to_right = !left_to_right;
            res.push_back(temp);
        }
        return res;
    }
};