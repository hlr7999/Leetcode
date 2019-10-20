#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int n = A.size();
        for (auto a : A) {
            for (auto b : B) {
                ++mp[a+b];
            }
        }
        int res = 0;
        for (auto c : C) {
            for (auto d : D) {
                res += mp[-c-d];
            }
        }
        return res;
    }
};