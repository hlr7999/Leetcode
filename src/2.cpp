#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int c = 0; // carry
    ListNode* result = new ListNode(0);
    ListNode* ret = result;
    while (l1 && l2) {
        int sum = l1->val + l2->val + c;
        c = sum / 10;
        result->next = new ListNode(sum % 10);
        result = result->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        int sum = l1->val + c;
        c = sum / 10;
        result->next = new ListNode(sum % 10);
        result = result->next;
        l1 = l1->next;
    }
    while (l2) {
        int sum = l2->val + c;
        c = sum / 10;
        result->next = new ListNode(sum % 10);
        result = result->next;
        l2 = l2->next;
    }
    if (c) {
        result->next = new ListNode(1);
    }

    return ret->next;
};

int main() {

}