#include <vector>

using namespace std;

class Solution {
private:
    vector<long long> temp;
    vector<long long> sum;
    int lower, upper, count = 0;
    void mergeSort(int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
    void merge(int start, int mid, int end) {
        int right = mid + 1;
        int tIndex = start;
        int low = mid + 1, high = mid + 1;
        for (int left = start; left <= mid; ++left) {
            while (low <= end && sum[low] - sum[left] < lower) {
                ++low;
            }
            while (high <= end && sum[high] - sum[left] <= upper) {
                ++high;
            }
            count += (high -low);
            while (right <= end && sum[right] < sum[left]) {
                temp[tIndex++] = sum[right++];
            }
            temp[tIndex++] = sum[left];
        }
        while (right <= end) {
            temp[tIndex++] = sum[right++];
        }
        for (int i = start; i <= end; ++i) {
            sum[i] = temp[i];
        }
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        sum.resize(nums.size() + 1);
        temp.resize(nums.size() + 1);
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        mergeSort(0, nums.size());
        return count;
    }
};
