//
//  main.cpp
//  Leetcode-208
//
//  Created by Jing Luo on 12/14/20.
//

#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        isWord = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i ++) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i ++) {
            if (p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size() && p; i ++) {
            p = p->next[word[i] - 'a'];
        }
        return p && p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size() && p; i ++) {
            p = p->next[prefix[i] - 'a'];
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    string word = "jing";
    string prefix = "gjin";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    std::cout << param_2 << "\n";
    std::cout << param_3 << "\n";
    return 0;
}
