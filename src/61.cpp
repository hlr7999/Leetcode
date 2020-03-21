#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        // get number of nodes
        int n = 1;
        ListNode* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            ++n;
        }
        cur->next = head;
        // find the new head
        k %= n;
        for (int i = 0; i < n - k - 1; ++i) {
            head = head->next;
        }
        ListNode* res = head->next;
        head->next = NULL;
        return res;
    }
};