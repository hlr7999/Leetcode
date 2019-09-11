#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
        return {};
    }
    static const vector<string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i] - '0';
        string str = strs[num];
        if (str.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < str.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + str[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}

int main() {
    
}