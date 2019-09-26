#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *pre = NULL, *cur = head, *post = head->next;
        while (post) {
            cur->next = pre;
            pre = cur;
            cur = post;
            post = post->next;
        }
        cur->next = pre;
        return cur;
    }
};