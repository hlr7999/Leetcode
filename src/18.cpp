#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size() - 3;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> temp = threeSum(nums, target - nums[i], i);
            while (i + 1 < n && nums[i] == nums[i+1]) {
                ++i;
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int second = start + 1; second < n; ++second) {
            int third = second + 1, end = n - 1;
            while (third < end) {
                int sum = nums[second] + nums[third] + nums[end];
                if (sum == target) {
                    int third_val = nums[third], end_val = nums[end];
                    while (third < end && nums[third] == third_val) {
                        ++third;
                    }
                    while (third < end && nums[end] == end_val) {
                        --end;
                    }
                    res.push_back({nums[start], nums[second], third_val, end_val});
                } else if (sum > target) {
                    --end;
                } else {
                    ++third;
                }
            }
            while (second + 1 < n && nums[second + 1] == nums[second]) {
                ++second;
            }
        }
        return res;
    }
};