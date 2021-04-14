#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long dp1 = 0, dp2 = 0;
        int p1 = n1 - 1, p2 = n2 - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] == nums2[p2]) {
                dp1 = dp2 = nums1[p1] + max(dp1, dp2);
                --p1; --p2;
            } else if (nums1[p1] > nums2[p2]) {
                dp1 += nums1[p1--];
            } else {
                dp2 += nums2[p2--];
            }
        }
        while (p1 >= 0) {
            dp1 += nums1[p1--];
        }
        while (p2 >= 0) {
            dp2 += nums2[p2--];
        }
        long long mod = 1e9 + 7;
        return max(dp1, dp2) % mod;
    }
};