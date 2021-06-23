struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *preLeft = new ListNode(0, head);
        for (int pos = 1; pos < left; ++pos) {
            preLeft = preLeft->next;
        }
        ListNode *pre = preLeft->next;
        ListNode *cur = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        preLeft->next->next = cur;
        preLeft->next = pre;
        return left == 1 ? preLeft->next : head;
    }
};