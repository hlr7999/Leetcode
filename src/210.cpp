#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> pre_course(numCourses, 0);
        // have to learn p[1] first
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++pre_course[p[0]];
        }
        queue<int> qu;
        for (int i = 0; i < pre_course.size(); ++i) {
            if (pre_course[i] == 0) qu.push(i);
        }
        vector<int> res;
        while (!qu.empty()) {
            int course = qu.front(); qu.pop();
            res.push_back(course);
            for (auto& post_course : graph[course]) {
                if (--pre_course[post_course] == 0)
                    qu.push(post_course);
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};