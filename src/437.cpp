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
    // recursive dfs
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathSumFrom(root, sum) + pathSum(root->left, sum)
            + pathSum(root->right, sum);
    }
    int pathSumFrom(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return (root->val == sum ? 1 : 0) +
            pathSumFrom(root->left, sum - root->val) +
            pathSumFrom(root->right, sum - root->val);
    }
    // recursive map
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        mp[0] = 1;
        recur(root, 0, sum);
        return res;
    }
    void recur(TreeNode* root, int cur, int sum) {
        if (root == NULL) return;
        cur += root->val;
        if (mp[cur-sum])
            res += mp[cur-sum];
        if (mp[cur]) ++mp[cur];
        else mp[cur] = 1;
        recur(root->left, cur, sum);
        recur(root->right, cur, sum);
        --mp[cur];
    }

private:
    unordered_map<int, int> mp;
    int res = 0;
};