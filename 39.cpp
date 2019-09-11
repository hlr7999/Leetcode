#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        }
        int i = start;
        for (; i < candidates.size() && candidates[i] <= remain; ++i) {
            temp.push_back(candidates[i]);
            backtrack(candidates, result, temp, remain - candidates[i], i);
            temp.pop_back();
        }
    }
};

int main() {

}