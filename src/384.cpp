#include <vector>
#include <iostream>

using namespace std;

static int __ = []() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   return 0;
}();

class Solution {
private:
    vector<int> arr, o_arr;

public:
    Solution(vector<int>& nums) {
        o_arr = arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr = o_arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = arr.size() - 1; i > 0; --i) {
            swap(arr[i], arr[rand() % (i + 1)]);
        }
        return arr;
    }
};