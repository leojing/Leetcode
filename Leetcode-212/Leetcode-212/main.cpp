//
//  main.cpp
//  Leetcode-212
//
//  Created by Jing Luo on 12/6/20.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TrieNode{
    string word = "";
    TrieNode* next[26];
};

TrieNode* root;
    
void addWord(const string& word) {
    TrieNode* p = root;
    for (int i = 0; i < word.size(); ++ i) {
        if (!p->next[word[i] - 'a']) {
            p->next[word[i] - 'a'] = new TrieNode();
        }
        p = p->next[word[i] - 'a'];
    }
    p->word = word;
}

void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, vector<string>& result){
    if(x<0||x>=board.size()||y<0||y>=board[0].size()) {
        return;
    }
    char c = board[x][y];
    if (c == '*' || !root->next[c - 'a']) { // already visited or not fund in Trie
        return;
    }
    
    root = root->next[c- 'a'];
    if (root->word != "") {  // found one
        result.emplace_back(root->word);
        root->word = ""; // de-duplicate
    }
    board[x][y] = '*';
    findWords(board, x+1, y, root, result);
    findWords(board, x-1, y, root, result);
    findWords(board, x, y+1, root, result);
    findWords(board, x, y-1, root, result);
    board[x][y] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new TrieNode();
    for (int i = 0; i < words.size(); ++ i) {
        addWord(words[i]);
    }
    vector<string> result;
    
    for (int i = 0; i < board.size(); ++ i) {
        for (int j = 0; j < board[0].size(); ++ j) {
            findWords(board, i, j, root, result);
        }
    }
    return result;
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
