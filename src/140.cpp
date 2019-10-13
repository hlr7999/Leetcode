#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // dfs
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> mp;
        return dfs(s, words, mp);
    }
    vector<string> dfs(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& mp) {
        if (mp.find(s) != mp.end()) {
            return mp[s];
        }
        vector<string> sentences;
        if (s.empty()) {
            return {""};
        }
        for (string word : wordDict) {
            if (s.size() >= word.size() && s.substr(0, word.size()) == word) {
                vector<string> subs = dfs(s.substr(word.size()), wordDict, mp);
                for (string sub : subs) {
                    sentences.push_back(word + (sub.size() ? " " + sub : ""));
                }
            }
        }
        mp[s] = sentences;
        return sentences;
    }
};