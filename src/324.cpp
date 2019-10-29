#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*(i)) % (n|1)]

        int i = 0, low = 0, high = n - 1;
        while (i <= high) {
            if (A(i) > mid)
                swap(A(i++), A(low++));
            else if (A(i) < mid)
                swap(A(i), A(high--));
            else ++i;
        }
    }
};