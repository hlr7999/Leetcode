class Solution {
public:
    int mySqrt(int x) {
        int lo = 0, hi = x;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid > x/mid)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return hi;
    }
};