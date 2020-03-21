#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(candidates, result, temp, target, 0);
        return result;
    };
    
    void backtrack(vector<int>& candidates, vector<vector<int>>& result,
    vector<int>& temp, int remain, int start) {
        if (!remain) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= remain; ++i) {
            temp.push_back(candidates[i]);
            backtrack(candidates, result, temp, remain - candidates[i], i + 1);
            temp.pop_back();
            while (i < candidates.size() - 1 && candidates[i+1] == candidates[i]) {
                ++i;
            }
        }
    }
};