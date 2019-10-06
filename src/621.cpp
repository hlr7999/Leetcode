#include <vector>
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
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char c : tasks)
            ++mp[c - 'A'];
        sort(mp.begin(), mp.end());
        int max_num = mp[25] - 1;
        int idle = max_num * n;
        for (int i = 24; i >= 0 && mp[i] > 0; --i)
            idle -= min(mp[i], max_num);
        return idle > 0 ? idle + tasks.size() : tasks.size();
    }
};