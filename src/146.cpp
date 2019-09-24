#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key;
    int val;
    DLinkedNode* pre;
    DLinkedNode* post;
    DLinkedNode(int k = 0, int v = 0) :
        key(k), val(v), pre(NULL), post(NULL) {}
};

class LRUCache {
private:
    int capacity;
    int count;
    unordered_map<int, DLinkedNode*> mp;
    DLinkedNode *head, *tail;

    void addNode(DLinkedNode* node) {
        node->pre = head;
        node->post = head->post;
        head->post->pre = node;
        head->post = node;
    }

    void removeNode(DLinkedNode* node) {
        node->pre->post = node->post;
        node->post->pre = node->pre;
    }

    void moveToHead(DLinkedNode* node) {
        this->removeNode(node);
        this->addNode(node);
    }

    DLinkedNode* popTail() {
        DLinkedNode* pre_tail = tail->pre;
        this->removeNode(pre_tail);
        return pre_tail;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->post = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        DLinkedNode* node = mp[key];
        if (node == NULL)
            return -1;
        this->moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        DLinkedNode* node = mp[key];
        if (node == NULL) {
            DLinkedNode* new_node = new DLinkedNode(key, value);
            mp[key] = new_node;
            addNode(new_node);
            if (count == capacity) {
                DLinkedNode* pre_tail = popTail();
                mp.erase(pre_tail->key);
            } else {
                ++count;
            }
        } else {
            node->val = value;
            moveToHead(node);
        }
    }
};