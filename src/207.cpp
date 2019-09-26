#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // bfs
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        while (!qu.empty()) {
            int course = qu.front(); qu.pop();
            ++count;
            for (auto& post_course : graph[course]) {
                if (--pre_course[post_course] == 0)
                    qu.push(post_course);
            }
        }
        return count == numCourses;
    }
};