//
//  main.cpp
//  Leetcode-1048
//
//  Created by Jing Luo on 4/25/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/* TLE 超时
bool isAncestor(string a, string b) {
    if (a.size() + 1 != b.size()) return false;
    int i = 0;
    for (int j = 0; j < b.size() && i < a.size(); ++ j) {
        if (a[i] == b[j]) {
            ++ i;
        }
    }
    return i == a.size();
}
 
int longestStrChain(vector<string>& words) {
    unordered_set<string> hasAncestor;
    unordered_map<string, vector<string>> mapping;
    for (int i = 0; i < words.size(); i ++) {
        for (int j = 0; j < words.size(); j ++) {
            if (j != i && isAncestor(words[i], words[j])) {
                mapping[words[i]].emplace_back(words[j]);
                hasAncestor.insert(words[j]);
            }
        }
    }
    
    queue<string> q;
    for (auto word: words) {
        if (hasAncestor.find(word) == hasAncestor.end()) {
            q.push(word);
        }
    }
    
    int level = 0;
    while (!q.empty()) {
        level++;
        int size = q.size();
        while (size --) {
            string top = q.front();
            q.pop();
            vector<string> curr = mapping[top];
            for (auto s: curr) {
                q.push(s);
            }
        }
    }
    return level;
}
*/

bool isAncestor(const string& a, const string& b) {
    if (a.size() + 1 != b.size()) return false;
    int i = 0;
    for (int j = 0; j < b.size() && i < a.size(); ++ j) {
        if (a[i] == b[j]) {
            ++ i;
        }
    }
    return i == a.size();
}
 
int longestStrChain(vector<string>& words) {
     sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
    
    int result = 0;
    int n = words.size();
    int dp[n];
    for (int i = 0; i < n; ++ i) {
        dp[i] = 1;
    }
    
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (isAncestor(words[j], words[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};//{"a","b","ba","bca","bda","bdca"};
    std::cout << longestStrChain(words) << "\n";
    return 0;
}


// time: O(n^2*m), n 是words的size，m是word的长度
// space: o(n)
