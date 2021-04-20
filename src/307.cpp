#include <vector>

using namespace std;

// Approach 1: Fenwick Tree / Binary Indexed Tree
class NumArray {
private:
    vector<int> num;
    vector<int> BIT;
    int n;
    void updateBIT(int i, int val) {
        while (i <= n) {
            BIT[i] += val;
            i += (i & (-i));
        }
    }
    int querySum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= (i & (-i));
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums): num(move(nums)), BIT(num.size()+1, 0) {
        n = num.size();
        for (int i = 0; i < n; ++i) {
            updateBIT(i+1, num[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - num[index];
        num[index] = val;
        updateBIT(index+1, diff);
    }
    
    int sumRange(int left, int right) {
        return querySum(right + 1) - querySum(left);
    }
};

// Approach 2: Segment Tree
class NumArray {
private:
    vector<int> segmentTree;
    int n;
    void buildTree(vector<int>& nums) {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            segmentTree[i] = nums[j];
        }
        for (int i = n - 1; i > 0; --i) {
            segmentTree[i] = segmentTree[i * 2] + segmentTree[i * 2 + 1];
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(2 * n);
        buildTree(nums);
    }
    
    void update(int index, int val) {
        index += n;
        segmentTree[index] = val;
        while (index > 0) {
            int left = index, right = index;
            if (index & 1) {
                left = index - 1;
            } else {
                right = index + 1;
            }
            segmentTree[index/2] = segmentTree[left] + segmentTree[right];
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) {
            if (left & 1) {
                sum += segmentTree[left++];
            }
            if (right & 1 == 0) {
                sum += segmentTree[right--];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};
