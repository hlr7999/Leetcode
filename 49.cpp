#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for (string s : strs) {
            mp[toCharCount(s)].push_back(s);
        }
        for (auto& v : mp) {
            result.push_back(v.second);
        }
        return result;
    };

    string toCharCount(string str) {
        string s(26, '0');
        for (char c : str) {
            s[c - 'a'] += 1;
        }
        return s;
    }
};