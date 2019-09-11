#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recFunc(result, "", 0, 0, n);
        return result;
    };

    void recFunc(vector<string>& result, string str, int left, int right, int n) {
        if (str.size() == n*2) {
            result.push_back(str);
            return;
        }
        if (left < n) {
            recFunc(result, str + '(', left + 1, right, n);
        }
        if (right < left) {
            recFunc(result, str + ')', left, right + 1, n);
        }
    }
};

int main() {

}