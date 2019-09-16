class Solution {
public:
    // Combination C(m+n-2,n-1)
    int uniquePaths(int m, int n) {
        int total_steps = m + n - 2;
        int one_direct = n - 1;
        if (m < n) {
            one_direct = m - 1;
        }
        long long result = 1;
        for (int i = 0; i < one_direct; ++i) {
            result = result * (total_steps - i) / (i + 1);
        }
        return result;
    }
};