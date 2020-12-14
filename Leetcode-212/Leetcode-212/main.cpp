//
//  main.cpp
//  Leetcode-212
//
//  Created by Jing Luo on 12/6/20.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

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
    TrieNode* getRoot(){return root;}

    /** Initialize your data structure here. */
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i ++) {
            insert(words[i]);
        }
    }

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

    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size() && p; i ++) {
            p = p->next[word[i] - 'a'];
        }
        return p && p->isWord;
    }

    bool startWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size() && p; i ++) {
            p = p->next[prefix[i] - 'a'];
        }
        return p;
    }
};

void help(int x, int y, vector<vector<char>>& board, TrieNode* root, string current, set<string>& result) {
    if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
    if(root->next[board[x][y]-'a'] != NULL){
        current=current+board[x][y];
        root=root->next[board[x][y]-'a'];
        if(root->isWord) result.insert(current);
        char c=board[x][y];
        board[x][y]=' ';
        help(x+1, y, board, root, current, result);
        help(x-1, y, board, root, current, result);
        help(x, y+1, board, root, current, result);
        help(x, y-1, board, root, current, result);
        board[x][y]=c;
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int row = int(board.size());
    int col = 0;
    if (row > 0) {
        col = int(board[0].size());
    }
    Trie* trie = new Trie(words);
    TrieNode* root = trie->getRoot();
    set<string> result;
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++) {
            string current = "";
            help(i, j, board, root, current, result);
        }
    }
    vector<string> res(result.begin(), result.end());
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}; //{{'a','b'}, {'c', 'd'}};
    vector<string> words = {"oath","pea","eat","rain"}; // {"abcd"};
    std::cout << findWords(board, words).size() << "\n";
    return 0;
}

/*Test case"
 [["a","a"]]
 ["a"]
 expected: ["a"]
 
 */
