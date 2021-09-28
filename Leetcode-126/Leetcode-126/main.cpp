//
//  main.cpp
//  Leetcode-126
//
//  Created by Jing Luo on 9/17/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void dfs(string key, string endWord, unordered_map<string, vector<string>> from, vector<string> path, vector<vector<string>>& ladder) {
    if (key == endWord) {
        ladder.push_back(path);
        path.clear();
        return;
    }
    vector<string> parents = from[key];
    for (auto parent: parents) {
        path.push_back(parent);
        dfs(parent, endWord, from, path, ladder);
        path.pop_back();
    }
}

// BFS 构建单词关系图，得到结果from，保存 key：单词，value：可以变换的单词
void bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string, vector<string>>& from) {
    unordered_set<string> dict = {wordList.begin(), wordList.end()};
    dict.erase(beginWord);
    
    queue<string> q;
    q.push(beginWord);
    unordered_map<string, int> steps = {{beginWord, 0}};
    vector<string> parents;
    int step = 1;
    steps[beginWord] = step;
    bool found = false;
    while (!q.empty()) {
        int len = (int)q.size();
        for (int i = 0; i < len; i ++) {
            string current = q.front();
            q.pop();
            for (int t = 0; t < current.size(); t ++) {
                char c = current[t];
                for (int k = 'a'; k <= 'z'; k ++) {
                    current[t] = k;
                    //表示在当前层已经遇到过，肯定有效，加入parents
                    if (steps[current] == step + 1) {
                        parents.push_back(current);
                        q.push(current);
                        continue;
                    }
                    //表示之前已经遇到过current，那层数肯定比当前层低，没必要再加入到后续结果中，直接删除，跳过
                    if (steps[current] != 0 && steps[current] < step + 1) {
                        dict.erase(current);
                        continue;
                    }
                    //表示如果不在dict中，则不存在，直接跳过
                    if (dict.find(current) == dict.end()) {
                        continue;
                    }
                    parents.push_back(current);
                    steps[current] = step + 1;
                    q.push(current);
                    if (current == endWord) {
                        found = true;
                    }
                }
                current[t] = c;
            }
            from[current] = parents;
            parents.clear();
        }
        if (found) {
            break;
        }
        step ++;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ladder;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return ladder;
    }

    unordered_map<string, vector<string>> from = {{beginWord, {}}};
    bfs(beginWord, endWord, wordList, from);
    
    vector<string> path = {beginWord};
    dfs(beginWord, endWord, from, path, ladder);
    return ladder;
}

int main(int argc, const char * argv[]) {
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> result = findLadders("red", "tax", wordList);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 "red"
 "tax"
 ["ted","tex","red","tax","tad","den","rex","pee"]
 */
