#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> mp;
            int dup = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    ++dup;
                } else {
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1];
                    int g = gcd(dx, dy);
                    ++mp[to_string(dy/g) + "/" + to_string(dx/g)];
                }
            }
            ans = max(ans, dup);
            for (auto p : mp) {
                ans = max(ans, p.second + dup);
            }
        }
        return ans;
    }
private:
    int gcd(int a, int b) {
        int t;
        while (b) {
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};