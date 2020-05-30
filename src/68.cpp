#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, cur;
        int num_of_letters = 0;
        for (string& w : words) {
            if (num_of_letters + cur.size() + w.size() > maxWidth) {
                int cur_size = cur.size();
                if (cur_size == 1) cur_size = 2;
                for (int i = 0; i < maxWidth - num_of_letters; ++i) {
                    cur[i % (cur_size-1)] += ' ';
                }
                string str;
                for (string& s : cur)
                    str += s;
                res.push_back(str);
                cur.clear();
                num_of_letters = 0;
            }
            cur.push_back(w);
            num_of_letters += w.size();
        }
        string str;
        for (int i = 0; i < cur.size() - 1; ++i) {
            str += cur[i] + ' ';
        }
        str += cur.back();
        int space_num = maxWidth - str.size();
        for (int i = 0; i < space_num; ++i) {
            str += ' ';
        }
        res.push_back(str);
        return res;
    }
};