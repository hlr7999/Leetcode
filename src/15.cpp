#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n && nums[i] <= 0; ++i) {
        int target = -nums[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
                ++left;
            } else if (sum > target) {
                --right;
            } else {
                int left_val = nums[left];
                int right_val = nums[right];
                while (left < right && nums[left] == left_val) {
                    ++left;
                }
                while (left < right && nums[right] == right_val) {
                    --right;
                }
                result.push_back({nums[i], left_val, right_val});
            }
        }

        while (i + 1 < n && nums[i + 1] == nums[i]) {
            ++i;
        }
    }

    return result;
}

int main() {

}