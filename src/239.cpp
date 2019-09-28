#include <vector>
#include <queue>
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
    // Approch 1 : monotonic queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mq;
        // init
        for (int i = 0; i < k-1; ++i) {
            while (!mq.empty() && nums[mq.back()] < nums[i])
                mq.pop_back();
            mq.push_back(i);
        }
        // loop
        vector<int> res;
        for (int i = k-1; i < nums.size(); ++i) {
            if (!mq.empty() && mq.front() < i-k+1)
                mq.pop_front();
            while (!mq.empty() && nums[mq.back()] < nums[i])
                mq.pop_back();
            mq.push_back(i);
            res.push_back(nums[mq.front()]);
        }
        return res;
    }
    // Approche 2 : two pass
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> left_max(n), right_max(n+1);
        right_max[n] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            left_max[i] = i % k == 0 ? nums[i] : max(left_max[i-1], nums[i]);
            int r_i = n - 1 - i;
            right_max[r_i] = (r_i+1) % k == 0 ? nums[r_i] : max(right_max[r_i+1], nums[r_i]);
        }
        vector<int> res(n-k+1);
        for (int i = 0; i < n-k+1; ++i) {
            res[i] = max(right_max[i], left_max[i+k-1]);
        }
        return res;
    }
};