#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int max_pos = 0, max_candy = 1, res = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                if (max_pos != i - 1) {
                    max_candy = 1;
                }
                max_pos = i;
                ++max_candy;
                res += max_candy;
            } else if (ratings[i] == ratings[i-1]) {
                max_pos = i;
                max_candy = 1;
                res += max_candy;
            } else {
                int given = i - max_pos;
                res += given;
                if (max_candy <= given) {
                    ++max_candy;
                    res += 1;
                }
            }
        }
        return res;
    }
};