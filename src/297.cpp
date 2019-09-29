#include <string>
#include <sstream>
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

class Codec {
private:
    void buildStr(ostringstream& str, TreeNode* node) {
        if (node) {
            str << node->val << ' ';
            buildStr(str, node->left);
            buildStr(str, node->right);
        } else {
            str << "# ";
        }
    }

    TreeNode* buildTree(istringstream& str) {
        string val;
        str >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(str);
        node->right = buildTree(str);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream res;
        buildStr(res, root);
        return res.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return buildTree(in);
    }
};