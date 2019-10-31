#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

typedef pair<int, int> line;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<line> lines;
        for (auto& b : buildings) {
            lines.push_back(make_pair(b[0], -b[2]));
            lines.push_back(make_pair(b[1], b[2]));
        }
        sort(lines.begin(), lines.end(), [](line a, line b) {
            return a.first == b.first ? a.second < b.second :
                a.first < b.first;
        });
        multiset<int, greater<int>> height;
        height.insert(0);
        int pre = 0;
        for (auto& line : lines) {
            if (line.second < 0) {
                height.insert(-line.second);
            } else {
                height.erase(height.find(line.second));
            }
            int cur = *(height.begin());
            if(cur != pre){
                pre = cur;
                res.push_back(vector<int>{line.first, cur});
            }
        }
        return res;
    }
};