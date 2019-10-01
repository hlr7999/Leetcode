#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // dp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    // another way
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        sort(coins.begin(), coins.end());
        helper(coins, amount, coins.size() - 1, 0, res);
        return res == INT_MAX ? -1 : res;
    }
    void helper(vector<int>& coins, int target, int start, int cur, int& res) {
        if (start < 0) return;
        int coin = coins[start];
        if (target % coin == 0) {
            res = min(res, cur + target/coin);
            return;
        }
        for (int num = target/coin; num >= 0; --num) {
            if (cur + num > res - 1) break;
            helper(coins, target - num*coin, start - 1, cur + num, res);
        }
    }
};