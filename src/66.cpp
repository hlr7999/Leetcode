#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        int c = 1;
        while (c && index >= 0) {
            c = ++digits[index] / 10;
            if (c) {
                digits[index] = 0;
                --index;
            }
        }
        if (index < 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};