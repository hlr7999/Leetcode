#include <vector>
#include <queue>

using namespace std;

// Dynamic Programming
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int t = i; t >= 0 && dp[t] >= stations[i][0]; --t) {
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
            }
        }
        for (int t = 0; t <= n; ++t) {
            if (dp[t] >= target) return t;
        }
        return -1;
    }
};

// Greedy
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxDistance = startFuel, stops = 0, i = 0;
        int n = stations.size();
        while (maxDistance < target) {
            while (i < n && stations[i][0] <= maxDistance) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            maxDistance += pq.top();
            pq.pop();
            ++stops;
        }
        return stops;
    }
};
