#include <vector>

using namespace std;

class Solution {
public:
    // One Pass
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profile = 0;
        for (int i : prices) {
            if (i < min_price) {
                min_price = i;
            }
            if (i - min_price > max_profile) {
                max_profile = i - min_price;
            }
        }
        return max_profile;
    }
};