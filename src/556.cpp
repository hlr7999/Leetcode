#include <string>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string str_n = to_string(n);
        int i = str_n.size() - 1;
        while (i > 0 && str_n[i] <= str_n[i-1]) --i;
        if (i > 0) {
            int j = i;
            while (j < str_n.size() && str_n[j] > str_n[i-1])
                ++j;
            swap(str_n[i-1], str_n[j-1]);
        } else return -1;
        int start = i, end = str_n.size() - 1;
        while (start < end) {
            swap(str_n[start], str_n[end]);
            ++start; --end;
        }
        long long ans = atoll(str_n.c_str());
        return ans > INT_MAX ? -1 : ans;
    }
};