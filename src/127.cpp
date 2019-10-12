#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // two-end bfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> *beg_set = new unordered_set<string>();
        unordered_set<string> *end_set = new unordered_set<string>();
        unordered_set<string> no_visited(wordList.begin(), wordList.end());
        if (no_visited.find(endWord) == no_visited.end())
            return 0;
        int ladder = 2;
        beg_set->insert(beginWord);
        end_set->insert(endWord);
        while (!beg_set->empty() && !end_set->empty()) {
            if (beg_set->size() > end_set->size()) {
                unordered_set<string> *t = beg_set;
                beg_set = end_set;
                end_set = t;
            }
            unordered_set<string> temp;
            for (auto it = beg_set->begin(); it != beg_set->end(); ++it) {
                string word = *it;
                for (int i = 0; i < word.size(); ++i) {
                    char old = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (end_set->find(word) != end_set->end())
                            return ladder;
                        if (no_visited.find(word) != no_visited.end()) {
                            no_visited.erase(word);
                            temp.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            ++ladder;
            beg_set->swap(temp);
        }
        delete beg_set;
        delete end_set;
        return 0;
    }
};