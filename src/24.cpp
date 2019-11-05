#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* res = new ListNode(0);
        ListNode* cur_pair = head;
        ListNode* pre = res;
        while (cur_pair != NULL && cur_pair->next != NULL) {
            ListNode* next_pair = cur_pair->next->next;
            pre->next = cur_pair->next;
            pre = cur_pair;
            cur_pair->next->next = cur_pair;
            cur_pair->next = next_pair;
            cur_pair = next_pair;
        }
        return res->next;
    }
};