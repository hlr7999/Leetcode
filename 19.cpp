#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pass = head;
    int count = 0;
    while (pass) {
        ++count;
        pass = pass->next;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    for (int i = 0; i < count - n; ++i) {
        head = head->next;
    }
    if (head->next) {
        head->next = head->next->next;
    }

    return dummy->next;
}

int main() {
    
}