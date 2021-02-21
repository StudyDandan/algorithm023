#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    bool bIsEnd;
    Trie* next[26];
public:

    /** Initialize your data structure here. */
    Trie() {
        bIsEnd = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) {
            size_t ch = word[i] - 'a';
            if (node->next[ch] == nullptr) {
                Trie* child = new Trie();
                node->next[ch] = child;
            }
            node = node->next[ch];
        }
        node->bIsEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto ch : word) {
            size_t i = ch - 'a';
            if (node->next[i] == nullptr) return false;
            node = node->next[i];
        }
        return node->bIsEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto ch : prefix) {
            size_t i = ch - 'a';
            if (node->next[i] == nullptr) return false;
            node = node->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */