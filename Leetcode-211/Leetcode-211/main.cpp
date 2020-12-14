//
//  main.cpp
//  Leetcode-211
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

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i ++) {
            if (p->next[word[i] - 'a'] == NULL) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* p = find(root, word);
        return p && p->isWord;
    }
    
private:
    TrieNode* find(TrieNode* p, string word) {
        for (int i = 0; i < word.size() && p; i ++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j ++) {
                    if (p->next[j]) { //用任何一个字符来匹配‘.’
                        int len = int(word.size()) - i - 1;
                        if (len >= 1) {
                            TrieNode* temp = find(p->next[j], word.substr(i+1, len));
                            if (temp && temp->isWord) {
                                return temp;
                            }
                        } else if (p->next[j]->isWord) {
                            return p->next[j];
                        } //如果找到了匹配的字符，直接返回，若没有，则继续寻找。
                    }
                }
                return NULL; //找遍所有的树，也没找到模糊匹配的，返回NULL
            } else {
                p = p->next[word[i] - 'a'];
            }
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    string word = "a";
    string searchWord = ".a";
    WordDictionary* obj = new WordDictionary();
    obj->addWord(word);
    bool param_2 = obj->search(searchWord);
    std::cout << param_2 << "\n";
    return 0;
}


/*
 解析文章： https://zhuanlan.zhihu.com/p/34747612
 ["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
 [[],["a"],["a"],["."],["a"],["a.a"],["a"],[".a..."],["a."]]
  */
