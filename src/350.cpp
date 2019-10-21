#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int num : nums1)
            ++mp[num];
        vector<int> res;
        for (int num : nums2) {
            if (mp[num]) {
                --mp[num];
                res.push_back(num);
            }
        }
        return res;
    }
};