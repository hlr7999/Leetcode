#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    // use map
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        Node* iter = head;
        while (iter) {
            mp[iter] = new Node(iter->val, NULL, NULL);
            iter = iter->next;
        }
        iter = head;
        while (iter) {
            mp[iter]->next = mp[iter->next];
            mp[iter]->random = mp[iter->random];
            iter = iter->next;
        }
        return mp[head];
    }
    // not use map
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        // link a node and its copy
        Node* iter = head;
        while (iter) {
            Node* node = new Node(iter->val, iter->next, NULL);
            iter->next = node;
            iter = node->next;
        }
        // copy andom
        iter = head;
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        // divide into original and copy list
        iter = head;
        Node* copy_head = head->next;
        Node* copy_iter = copy_head;
        while (copy_iter->next) {
            iter->next = copy_iter->next;
            iter = iter->next;
            copy_iter->next = iter->next;
            copy_iter = copy_iter->next;
        }
        iter->next = NULL;
        return copy_head;
    }
};