#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size();
        vector<long long> S(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            S[i+1] = S[i] + A[i];
        }
        deque<int> dqu;
        int res = N + 1;
        for (int y = 0; y < S.size(); ++y) {
            while (!dqu.empty() && S[dqu.back()] >= S[y]) {
                dqu.pop_back();
            }
            while (!dqu.empty() && S[y] - S[dqu.front()] >= K) {
                res = min(res, y - dqu.front());
                dqu.pop_front();
            }
            dqu.push_back(y);
        }
        return res == N + 1 ? -1 : res;
    }
};