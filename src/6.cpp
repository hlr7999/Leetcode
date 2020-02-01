#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res(s);
        int index = 0;
        int n = s.size();
        int step = 2 * numRows - 2;
        if (step == 0) step = 1;
        for (int i = 0; i < numRows; ++i) {
            int nIndex = i;
            while (nIndex < n) {
                res[index++] = s[nIndex];
                nIndex += step;
                if (i != 0 && i != numRows - 1 && nIndex - 2*i < n) {
                    res[index++] = s[nIndex - 2*i];
                }
            }
        }
        return res;
    }
};