#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre_k = dummy;
        int n = 0; ListNode* temp = head;
        while (temp) {
            ++n; temp = temp->next;
        }
        for (n = n - k; n >= 0; n -= k) {
            ListNode *pre = NULL, *cur = head, *next = cur->next;
            for (int i = 0; i < k; ++i) {
                cur->next = pre;
                pre = cur; cur = next;
                if (cur) next = cur->next;
            }
            pre_k->next = pre;
            pre_k = head;
            head = cur;
        }
        pre_k->next = head;
        return dummy->next;
    }
};