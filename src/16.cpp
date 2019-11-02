#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX, n = nums.size();
        for (int start = 0; start < n; ++start) {
            int mid = start + 1, end = n - 1;
            while (mid < end) {
                int sum = nums[start] + nums[mid] + nums[end];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    --end;
                } else {
                    ++mid;
                }
                if (abs(sum - target) < abs(min_diff)) {
                    min_diff = sum - target;
                }
            }
        }
        return target + min_diff;
    }
};