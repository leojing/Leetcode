//
//  main.cpp
//  Leetcode-127
//
//  Created by Jing Luo on 9/15/21.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool helper(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }
    int len = (int)a.size();
    bool flag = false;
    for (int i = 0; i < len; i ++) {
        if (a[i] != b[i]) {
            if (!flag) {
                flag = true;
            } else {
                return false;
            }
        }
    }
    return flag;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = (int)wordList.size();
    int exsit = -1;
    for (int i = 0; i < n; i ++) {
        if (endWord == wordList[i]) {
            exsit = i;
            break;
        }
    }
    if (exsit == -1) {
        return 0;
    }
    unordered_map<string,bool> availableWord;
    for (auto word: wordList) {
        availableWord[word] = helper(beginWord, word);
    }
    queue<string> q;
    q.push(endWord);
    unordered_set<string> visited;
    visited.insert(endWord);
    int ladder = 1;
    while (!q.empty()) {
        int len = (int)q.size();
        for (int i = 0; i < len; i ++) {
            string current = q.front();
            q.pop();
            if (availableWord[current]) {
                return ladder+1;
            }
            for (int i = 0; i < n; i ++) {
                if (helper(current, wordList[i]) && visited.find(wordList[i]) == visited.end()) {
                    visited.insert(wordList[i]);
                    q.push(wordList[i]);
                }
            }
        }
        ladder ++;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<string> wordList = {"hot","dot","dog","cog","lot","log"};
    std::cout << ladderLength("hit", "cog", wordList)  << "\n";
    return 0;
}

/*
"hit"
"cog"
{"hot","dot","dog","lot","log"};

"hit"
"cog"
{"hot","dot","dog","cog","lot","log"};

"hot"
"dog"
{"hot","dog"};
 
 
 
 time: O(n * m * m), n为wordlist长度，m为list中单词的长度，space: O(n * m)
*/
