#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

// Can use dp or bfs
// Manthematics solution (四平方和定理)
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        int sqrt_n = (int)sqrt(n);
        if (sqrt_n*sqrt_n == n)
            return 1; 
        for (int i = 1; i <= sqrt_n; ++i) {
            int j = n - i*i;
            int sqrt_j = (int)sqrt(j);
            if (sqrt_j*sqrt_j == j)
                return 2;
        }
        return 3;
    }
};