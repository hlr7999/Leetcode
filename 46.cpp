#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while (true) {
            result.push_back(nums);
            // find a[i] > a[i-1]
            int i = nums.size() - 1;
            while (i >= 1 && nums[i] <= nums[i - 1]) {
                --i;
            }
            if (i < 1) {
                break;
            }
            // find a[j] > a[i-1] (j > i)
            int j = i;
            while (j < nums.size() && nums[j] > nums[i - 1]) {
                ++j;
            }
            // swap a[j] and a[i-1]
            swap(nums[i - 1], nums[j - 1]);
            // reverse
            int start = i, end = nums.size() - 1;
            while (start < end) {
                swap(nums[start], nums[end]);
                ++start;
                --end;
            }
        }
        return result;
    }
};