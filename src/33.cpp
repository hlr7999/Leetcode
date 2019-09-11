#include <iostream>
#include <vector>

using namespace std;

// refer to
// https://leetcode.wang/leetCode-33-Search-in-Rotated-Sorted-Array.html
class Solution {
public:
    // Solution 1
    int search(vector<int>& nums, int target) {
        // find the index of the smallest number
        // also the offset of the array
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int offset = start;
        // binary search to find the target
        // this seatch is based on the array before rotation
        int n = nums.size();
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            // find the index of the mid element in the array after rotation
            int mid_after_rotation = (mid + offset) % n;
            if (target == nums[mid_after_rotation]) {
                return mid_after_rotation;
            }
            if (target < nums[mid_after_rotation]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // not found
        return -1;
    }
    // Solution 2
    int search(vector<int>& nums, int target) {
        // this solution is based on the fact that
        // if you cut the array in half,
        // there must be at least one part array is in order
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                // the left part is in order
                if (target < nums[mid] && target >= nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                // the right part is in order
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1 ;
                }
            }
        }
        return -1;
    }
};

int main() {

}