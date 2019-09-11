#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Approch1 backtarck (will get TLE)
    bool canJump(vector<int>& nums) {
        return backtrack(nums, 0);
    }
    bool backtrack(vector<int>& nums, int position) {
        if (position == nums.size() - 1) {
            return true;
        }
        int furthest = position + nums[position];
        if (furthest > nums.size() - 1) {
            furthest = nums.size() - 1;
        }
        for (int i = position + 1; i <= furthest; ++i) {
            if (backtrack(nums, i)) {
                return true;
            }
        }
        return false;
    }
    // Approch2 DP
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int* can_jump = new int[n];
        can_jump[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            int furthest = nums[i] + i;
            if (furthest > n - 1) {
                furthest = n - 1;
            }
            can_jump[i] = 0;
            for (int j = i + 1; j <= furthest; ++j) {
                if (can_jump[j]) {
                    can_jump[i] = 1;
                    break;
                }
            }
        }
        return can_jump[0];
    }
    // Approch3 greedy
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_can_jump = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= last_can_jump) {
                last_can_jump = i;
            }
        }
        return last_can_jump == 0;
    }
};