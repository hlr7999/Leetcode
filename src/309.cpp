#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // dp
    // see here
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
    int maxProfit(vector<int>& prices) {
        int sold = 0, hold = INT_MIN, rest = 0;
        for (int price : prices) {
            int pre_rest = rest;
            rest = max(sold, rest);
            sold = hold + price;
            hold = max(hold, pre_rest-price);
        }
        return max(sold, rest);
    }
};