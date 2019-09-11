#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator() (const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        for (ListNode* l : lists) {
            if (l) {
                pq.push(l);
            }
        }
        while (!pq.empty()) {
            ListNode* l = pq.top();
            pq.pop();
            head->next = l;
            head = head->next;
            if (l->next) {
                pq.push(l->next);
            }
        }
        return dummy->next;
    }
};

int main() {
    
}