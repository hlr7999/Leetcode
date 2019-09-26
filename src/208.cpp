#include <iostream>

using namespace std;

// speed up cin and cout
static int __ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

struct TrieNode {
    TrieNode* children[26];
    char val;
    bool is_word;
    TrieNode(char v) : is_word(false), val(v) {
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};

// https://en.wikipedia.org/wiki/Trie
class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == NULL) {
                node->children[i] = new TrieNode(c);
            }
            node = node->children[i];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == NULL) {
                return false;
            }
            node = node->children[i];
        }
        return node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (node->children[i] == NULL) {
                return false;
            }
            node = node->children[i];
        }
        return true;
    }
};