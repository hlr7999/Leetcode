#include <vector>

using namespace std;

class Solution {
public:
    // Approch1 backtracking
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, nums, temp, 0);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int start) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            backtrack(result, nums, temp, i + 1);
            temp.pop_back();
        }
    }
    // Approch2 bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int ans_num = 1 << n;
        for (int i = 0; i < ans_num; ++i) {
            vector<int> temp;
            int bit = 1;
            for (int index = 0; index < n; ++index) {
                if (bit & i) {
                    temp.push_back(nums[index]);
                }
                bit = bit << 1;
            }
            result.push_back(temp);
        }
        return result;
    }
};