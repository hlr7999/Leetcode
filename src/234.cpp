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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL)
            slow = slow->next;
        // reverse the second part
        ListNode *pre = NULL, *post = slow->next;
        while (post) {
            slow->next = pre;
            pre = slow;
            slow = post;
            post = post->next;
        }
        slow->next = pre;
        // judge
        while (slow) {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};