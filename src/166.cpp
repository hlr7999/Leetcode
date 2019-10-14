#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0)
            res += '-';
        // integral part
        long n = labs(numerator), d = labs(denominator);
        res += to_string(n / d);
        n %= d;
        if (n == 0) return res;
        res += '.';
        // fictional part
        unordered_map<long, int> mp;
        mp[n] = res.size();
        while (n) {
            n *= 10;
            res += to_string(n / d);
            n %= d;
            if (mp.find(n) != mp.end()) {
                res.insert(mp[n], 1, '(');
                res += ')';
                break;
            } else {
                mp[n] = res.size();
            }
        }
        return res;
    }
};