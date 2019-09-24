#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // hash set
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head) {
            if (set.find(head) != set.end())
                return head;
            set.insert(head);
            head = head->next;
        }
        return NULL;
    }
    // two points
    // if there has a cycle, the fast point must meet the slow one
    // and the second part can be proofed
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *fast = head->next, *slow = head;
        while (fast != slow) {
            if (fast == NULL || fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};