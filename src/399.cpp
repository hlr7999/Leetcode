#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < values.size(); ++i) {
            graph[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            if (values[i] != 0)
                graph[equations[i][1]].insert(make_pair(equations[i][0], 1.0 / values[i]));
        }
        vector<double> res;
        for (auto& q : queries) {
            unordered_set<string> visited;
            res.push_back(dfs(q[0], q[1], visited, graph));
        }
        return res;
    }
    double dfs(string start, string end, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& graph) {
        if (graph[start].find(end) != graph[start].end())
            return graph[start][end];
        for (auto& neighbors : graph[start]) {
            if (visited.find(neighbors.first) == visited.end()) {
                visited.insert(neighbors.first);
                double temp = dfs(neighbors.first, end, visited, graph);
                if (temp != -1.0) return temp*neighbors.second;
            }
        }
        return -1.0;
    }
};