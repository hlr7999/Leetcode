#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) {
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};