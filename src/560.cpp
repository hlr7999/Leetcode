#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // cumulative sum
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (mp[sum-k])
                count += mp[sum-k];
            ++mp[sum];
        }
        return count;
    }
};