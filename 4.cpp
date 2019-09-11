#include <vector>
#include <algorithm>

using namespace std;

// Merge solution O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int mid = (size1 + size2) / 2;
    mid += (size1 + size2) % 2;
    int pos1 = 0, pos2 = 0;
    int midNum = 0;
    for (int i = 0; i < mid; ++i) {
        if (pos1 < size1 && pos2 < size2) {
            if (nums1[pos1] < nums2[pos2]) {
                midNum = nums1[pos1];
                ++pos1;
            } else {
                midNum = nums2[pos2];
                ++pos2;
            }
        } else if (pos1 < size1) {
            midNum = nums1[pos1];
            ++pos1;
        } else {
            midNum = nums2[pos2];
            ++pos2;
        }
    }

    double ret = (double)midNum;
    if ((size1 + size2) & 1) {
        if (pos1 < size1 && pos2 < size2) {
            if (nums1[pos1] < nums2[pos2]) {
                ret = (ret + nums1[pos1]) / 2;
            } else {
                ret = (ret + nums2[pos2]) / 2;
            }
        } else if (pos1 < size1) {
            ret = (ret + nums1[pos1]) / 2;
        } else {
            ret = (ret + nums2[pos2]) / 2;
        }
    }

    return ret;
}

// Dichotomy solution O(log(m + n))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() == 0)
        return (nums2[nums2.size()/2]+nums2[(nums2.size()-1)/2])/2.0;
    if(nums2.size() == 0)
        return (nums1[nums1.size()/2]+nums1[(nums1.size()-1)/2])/2.0;
    int n = nums1.size();
    int m = nums2.size();
    if(n > m)   //保证数组1一定最短
        return findMedianSortedArrays(nums2,nums1);
    int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n+1长度
    while(lo <= hi)   //二分
    {
        c1 = (lo+hi)/2;  //c1是二分的结果
        c2 = m+n- c1;
        L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
        R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
        L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
        R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

        if(L1 > R2)
            hi = c1-1;
        else if(L2 > R1)
            lo = c1+1;
        else
            break;
    }

    return (max(L1,L2)+ min(R1,R2))/2.0;
}

int main() {

}