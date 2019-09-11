#include <vector>
#include <algorithm>

using namespace std;

// l: the sum of the sub array with largest sum
//    starting from the first element
// m: the sum of the sub array with largest sum
// r: the sum of the sub array with largest sum
//    ending at the last element
// s: the sum of the whole array
struct val {
    int l, m, r, s;
    val(int l, int m, int r, int s)
        :l(l), m(m), r(r), s(s){}
};

class Solution {
public:
    // Dynamic Programming
    int maxSubArray(vector<int>& nums) {
        int* dp = new int[nums.size()];
        dp[0] = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            if (dp[i] > max_sum) {
                max_sum = dp[i];
            }
        }
        return max_sum;
    }
    // Divide an Conquer
    val dac(vector<int>& nums, int start, int end) {
        if (start == end) {
            return val(nums[end], nums[end], nums[end], nums[end]);
        }
        int diff = end - start;
        val v1 = dac(nums, start, start + diff/2);
        val v2 = dac(nums, start + diff/2 + 1, end);
        int l, m, r, s;
        l = max(v1.l, v1.s + v2.l);
        m = max(v1.r + v2.l, max(v1.m, v2.m));
        r = max(v2.r, v1.r + v2.s);
        s = v1.s + v2.s;
        return val(l, m, r, s);
    }
    int maxSubArray(vector<int>& nums) {
        val v = dac(nums, 0, nums.size() - 1);
        return v.m;
    }
};