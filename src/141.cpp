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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head) {
            if (set.find(head) != set.end())
                return true;
            set.insert(head);
            head = head->next;
        }
        return false;
    }
    // two points
    // if there has a cycle, the fast point must meet the slow one
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *fast = head->next, *slow = head;
        while (fast != slow) {
            if (fast == NULL || fast->next == NULL)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};