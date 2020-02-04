#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0) {
            return {};
        }
        int word_num = words.size();
        int word_len = words[0].size();
        int s_len = s.size();
        vector<int> res;
        unordered_map<string, int> word_count;
        for (auto word : words) {
            ++word_count[word];
        }
        for (int i = 0; i < s_len - word_num*word_len + 1; ++i) {
            unordered_map<string, int> word_seen;
            int j = 0;
            while (j < word_num) {
                string word = s.substr(i + j * word_len, word_len);
                if (word_count.find(word) != word_count.end()) {
                    ++word_seen[word];
                    if (word_seen[word] > word_count[word]) {
                        break;
                    }
                } else break;
                ++j;
            }
            if (j == word_num) {
                res.push_back(i);
            }
        }
        return res;
    }
};