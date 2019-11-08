#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, cur_level_end = 0, cur_farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            cur_farthest = max(cur_farthest, i + nums[i]);
            if (i == cur_level_end) {
                jumps++;
                cur_level_end = cur_farthest;
            }
        }
        return jumps;
    }
};