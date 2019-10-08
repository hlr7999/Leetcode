#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return 0;
        string res = "";
        for (int id = 0; id < strs[0].size(); ++id) {
            for (int i = 1; i < strs.size(); ++i) {
                if (id >= strs[i].size() || strs[0][id] != strs[i][id])
                    return res;
            }
            res += strs[0][id];
        }
        return res;
    }
};