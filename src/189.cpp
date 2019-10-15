#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int cur = start, pre_num = nums[start];
            do {
                cur = (cur + k) % n;
                int temp = nums[cur];
                nums[cur] = pre_num;
                pre_num = temp;
                ++count;
            } while (cur != start);
        }
    }
};