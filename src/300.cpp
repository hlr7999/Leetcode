#include <vector>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // tail............
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        vector<int> tail(nums.size());
        for (int num : nums) {
            int lo = 0, hi = len;
            while (lo != hi) {
                int mid = (lo + hi) / 2;
                if (tail[mid] < num)
                    lo = mid + 1;
                else hi = mid;
            }
            tail[lo] = num;
            if (lo == len) ++len;
        }
        return len;
    }
};