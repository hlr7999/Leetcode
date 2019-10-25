#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *odd_cur = odd, *even_cur = even;
        while (even_cur && even_cur->next) {
            odd_cur->next = even_cur->next;
            odd_cur = odd_cur->next;
            even_cur->next = odd_cur->next;
            even_cur = even_cur->next;
        }
        odd_cur->next = even;
        return odd;
    }
};