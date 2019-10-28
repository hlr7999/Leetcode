#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    typedef vector<pair<int, int>> Piv;
    typedef Piv::iterator Piv_it;

public:
    // mergesort solution
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        if (n == 0) return res;
        Piv arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(make_pair(i, nums[i]));
        }
        mergeSort(res, arr.begin(), arr.end());
        return res;
    }
    void mergeSort(vector<int>& res, Piv_it beg, Piv_it end) {
        if (end - beg <= 1)
            return;
        Piv_it mid = beg + (end - beg) / 2;
        mergeSort(res, beg, mid);
        mergeSort(res, mid, end);
        Piv copy_left(beg, mid);
        Piv_it merge_it = beg;
        for(auto i = copy_left.begin(), j = mid; i != copy_left.end(); ++i){
            while(j != end && i->first > j->first) {
                *merge_it = *j;
                ++j; ++merge_it;
            }
            res[i->second] += j - mid;
            *merge_it = *i;
            ++merge_it;
        }
    }
};