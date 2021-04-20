class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1, mid = 0;
        // find the top
        int top = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        top = left;
        // find target in (left, top)
        left = 0; right = top;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        // find target in (top, right)
        left = top; right = mountainArr.length() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) < target) {
                right = mid - 1;
            } else if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        // not found
        return -1;
    }
};