#include <vector>

using namespace std;

// https://leetcode.com/problems/redundant-connection-ii/discuss/278105/topic
// 这个讲的很好，看这个吧
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), edge1, edge2;
        for (auto& e : edges) {
            if (parent[e[1]]) {
                edge1 = {parent[e[1]], e[1]};
                edge2 = e;
                e[1] = 0;
                break;
            } else {
                parent[e[1]] = e[0];
            }
        }
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto& e : edges) {
            if (e[1] == 0) continue;
            int pe0 = find(parent, e[0]);
            if (e[1] == pe0) {
                if (edge1.empty()) return e;
                else return edge1;
            }
            parent[e[1]] = pe0;
        }
        return edge2;
    }
private:
    int find(vector<int>& fa, int x) {
        return x == fa[x] ? x : (fa[x] = find(fa, fa[x]));
    }
};