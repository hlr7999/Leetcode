#include <vector>
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
    // BFPRT Algorithm (not the real BFPRT)
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int partition = qsPartition(nums, low, high);
            if (partition > k)
                high = partition - 1;
            else if (partition < k)
                low = partition + 1;
            else break;
        }
        return nums[k];
    }
    int qsPartition(vector<int>& nums, int low, int high) {
        // int mid = (low + high) / 2;
        // swap(nums[low], nums[mid]);
        int i = low, j = high + 1;
        while (i < j) {
            while (i < high && nums[++i] <= nums[low]);
            while (j > low && nums[--j] >= nums[low]);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[low]);
        return j;
    }
};