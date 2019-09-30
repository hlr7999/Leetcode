#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();


class Solution {
private:
    unordered_set<string> set;
    string str;

public:
    // dfs
    vector<string> removeInvalidParentheses(string s) {
        str = s;
        int left_del = 0, right_del = 0;
        for (char c : s) {
            if (c == '(') {
                ++left_del;
            } else if (c == ')') {
                if (left_del == 0)
                    ++right_del;
                else --left_del;
            }
        }
        dfs(0, 0, 0, left_del, right_del, "");
        return vector<string>(set.begin(), set.end());
    }
    void dfs(int depth, int left, int right, int left_del, int right_del, string cur) {
        if (depth == str.size()) {
            if (left == right && left_del == 0 && right_del == 0)
                set.insert(cur);
            return;
        }
        if (str[depth] == '(' && left_del > 0)
            dfs(depth+1, left, right, left_del-1, right_del, cur);
        else if (str[depth] == ')' && right_del > 0)
            dfs(depth+1, left, right, left_del, right_del-1, cur);
        if (str[depth] == '(')
            dfs(depth+1, left+1, right, left_del, right_del, cur+"(");
        else if (str[depth] != ')')
            dfs(depth+1, left, right, left_del, right_del, cur+str[depth]);
        else if (left > right)
            dfs(depth+1, left, right+1, left_del, right_del, cur+")");
    }
};