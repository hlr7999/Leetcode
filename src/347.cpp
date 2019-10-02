#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums)
            ++mp[num];

        vector<pair<int, int>> vmap;
        for (auto& item : mp)
            vmap.push_back(item);
        sort(vmap.begin(), vmap.end(), 
            [](const pair<int, int> &x, const pair<int, int> &y) -> int {
            return x.second > y.second;
        });

        vector<int> res(k);
        for (int i = 0; i < k; ++i)
            res[i] = vmap[i].first;
        return res;
    }
};