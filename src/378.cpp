#include <vector>
#include <queue>
#include <iostream>

using namespace std;

static int __ = []() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   return 0;
}();

struct Node {
    int val;
    int x, y;
    Node(int x, int y, int v) : val(v), x(x), y(y) {}
};

struct compare {
    bool operator()(const Node* l, const Node* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int j = 0; j < n; ++j) {
            pq.push(new Node(0, j, matrix[0][j]));
        }
        for (int i = 0; i < k; ++i) {
            Node* node = pq.top(); pq.pop();
            int nx = node->x + 1;
            if (nx < m) {
                pq.push(new Node(nx, node->y, matrix[nx][node->y]));
            }
        }
        return pq.top()->val;
    }
};

// binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = matrix[0][0], hi = matrix[m - 1][n - 1] + 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0,  j = n - 1;
            for(int i = 0; i < m; ++i) {
                while(j >= 0 && matrix[i][j] > mid) --j;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};