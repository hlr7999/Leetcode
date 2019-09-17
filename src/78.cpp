#include <vector>

using namespace std;

class Solution {
public:
    // backtracking
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
};