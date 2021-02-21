#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int last[26] = {0};
        for (int i = 0; i < S.size(); ++i) {
            last[S[i] - 'a'] = i;
        }
        int pre_pos = -1, last_pos = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (last[S[i] - 'a'] > last_pos) {
                last_pos = last[S[i] - 'a'];
            }
            if (i == last_pos) {
                res.push_back(last_pos - pre_pos);
                pre_pos = last_pos;
            }
        }
        return res;
    }
};