#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            while (cur->child == NULL && cur->next) {
                cur = cur->next;
            }
            if (cur->child) {
                Node* temp = cur->child;
                while (temp->next) temp = temp->next;
                temp->next = cur->next;
                if (cur->next)
                    cur->next->prev = temp;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            cur = cur->next;
        }
        return head;
    }
};