#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> ans(n + m, 0);
        string res(n + m, '0');
        int p1 = 0, p2 = 0, sum = 0;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); 
                p1 = i + j, p2 = i + j + 1;
                sum = mul + ans[p2];
                ans[p1] += sum / 10;
                ans[p2] = sum % 10;
            }
        }
        if (sum % 10 != 0) ++p1;
        for (int i = m + n - 1; i > p1; --i) {
            res[i] += ans[i];
        }
        return res.substr(p1 - 1, m + n - p1 - 1);
    }
};