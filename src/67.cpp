#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, a_pos = a.size() - 1, b_pos = b.size() - 1;
        int res_pos = max(a_pos, b_pos);
        string res(res_pos + 1, '0');
        while (res_pos >= 0) {
            int an = 0, bn = 0;
            if (a_pos >= 0) {
                an = a[a_pos] - '0';
            }
            if (b_pos >= 0) {
                bn = b[b_pos] - '0';
            }
            res[res_pos] = '0' + (an + bn + carry) % 2;
            carry = (an + bn + carry) / 2;
            --res_pos; --a_pos; --b_pos;
        }
        if (carry > 0) {
            res = '1' + res;
        }
        return res;
    }
};