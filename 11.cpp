#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0, left = 0, right = height.size() - 1;
    while (left < right) {
        int cur = min(height[left], height[right]) * (right - left);
        if (cur > max_area) {
            max_area = cur;
        }
        if (height[right] < height[left]) {
            --right;
        } else {
            ++left;
        }
    }
    return max_area;
}

int main() {

}