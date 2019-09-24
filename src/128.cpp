#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // use map !
    // mp[i] means the longest consecutive with boundary i
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_len = 0;
        for (int i : nums) {
            if (mp[i]) continue;
            mp[i] = mp[i-1] + mp[i+1] + 1;
            mp[i - mp[i-1]] = mp[i + mp[i+1]] = mp[i];
            max_len = max(max_len, mp[i]);
        }
        return max_len;
    }
};