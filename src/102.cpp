#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            vector<int> temp;
            TreeNode* t = nullptr;
            for (int i = 0; i < n; ++i) {
                t = qu.front(); qu.pop();
                if (t) {
                    temp.push_back(t->val);
                    qu.push(t->left);
                    qu.push(t->right);
                }
            }
            if (temp.size())
                result.push_back(temp);
        }
        return result;
    }
};