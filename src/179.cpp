#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int num){return num == 0;}))
            return "0";
        vector<string> arr;
        for (int i : nums)
            arr.push_back(to_string(i));
        sort(arr.begin(), arr.end(), [](string& l, string& r){
            return l + r > r + l;
        });
        string res = "";
        for (string& s : arr)
            res += s;
        return res;
    }
};