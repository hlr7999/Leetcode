#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    // PreSorting
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> result;
        vector<int> temp;
        if (intervals.size()) {
            temp = intervals[0];
        } else {
            return result;
        } 
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] <= temp[1] && temp[1] < interval[1]) {
                temp[1] = interval[1];
            } else if (interval[0] > temp[1]) {
                result.push_back(temp);
                temp = interval;
            }
        }
        result.push_back(temp);
        return result;
    }
};