#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        // find the left index
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        // not found
        if (nums.size() == 0 || nums[start] != target) {
            return result;
        }
        result[0] = start;
        // find the right index
        start = 0, end = nums.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        result[1] = start - 1;
        return result;
    }
};