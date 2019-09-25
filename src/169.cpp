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
    // Boyer-Moore Voting Algorithm !!!
    int majorityElement(vector<int>& nums) {
        int major, count = 0;
        for (int num : nums) {
            if (count == 0) {
                major = num;
                ++count;
            } else if (major == num) {
                ++count;
            } else --count;
        }
        return major;
    }
};