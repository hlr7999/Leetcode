#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode*, int> mp;

public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (mp[root]) return mp[root];
        int temp = 0;
        if (root->left)
            temp += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            temp += rob(root->right->left) + rob(root->right->right);
        temp = max(temp + root->val, rob(root->left) + rob(root->right));
        mp[root] = temp;
        return temp;
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto p = recur(root);
        return max(p.first, p.second);
    }
    pair<int, int> recur(TreeNode* root) {
        if(root == NULL) return {0, 0};
        auto l = recur(root->left);
        auto r = recur(root->right);
        int ex = max(l.first, l.second) + max(r.first, r.second);
        int in = root->val + l.second + r.second;
        return {in, ex};
    }
};