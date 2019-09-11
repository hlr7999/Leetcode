#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// create the permutation just larger than the current one
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find a[i] > a[i-1]
        int i = nums.size() - 1;
        while (i >= 1 && nums[i] <= nums[i - 1]) {
            --i;
        }
        // find a[j] > a[i-1] (j > i)
        if (i >= 1) {
            int j = i;
            while (j < nums.size() && nums[j] > nums[i - 1]) {
                ++j;
            }
            // swap a[j] and a[i-1]
            swap(nums[i - 1], nums[j - 1]);
        }
        // reverse
        int start = i, end = nums.size() - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};

int main() {

}