#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = nums[0];
        int imax = max_pro, imin = max_pro;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num < 0) {
                int temp = imax;
                imax = max(num, num*imin);
                imin = min(num, num*temp);
            } else {
                imax = max(num, num*imax);
                imin = min(num, num*imin);
            }

            if (imax > max_pro)
                max_pro = imax;
        }
        return max_pro;
    }
};