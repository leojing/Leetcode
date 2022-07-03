//
//  main.cpp
//  Leetcode-886
//
//  Created by Jing Luo on 7/3/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canGroup = true;

void helper(int k, int groupNum, unordered_map<int, int>& grouped, unordered_map<int, vector<int>>& dislike) {
    if (!canGroup) {
        return;
    }
    grouped[k] = groupNum;
    for (int i = 0; i < dislike[k].size(); i ++) {
        if (grouped[dislike[k][i]] ==  groupNum) {
            canGroup = false;
            return;
        }
        if (grouped[dislike[k][i]] != -1) {
            continue;
        }
        helper(dislike[k][i], (groupNum + 1) % 2, grouped, dislike);
    }
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    unordered_map<int, int> grouped;
    unordered_map<int, vector<int>> dislike;
    
    for (int i = 1; i <= n; i ++) {
        grouped[i] = -1;
    }
    
    for (auto i: dislikes) {
        if (dislike.find(i[0]) == dislike.end()) {
            dislike[i[0]] = vector<int>();
        }
        dislike[i[0]].emplace_back(i[1]);
        // 这里需要注意[1,5], [5,6], 要将 1，6 都放入5的dislike，不能只放6
        if (dislike.find(i[1]) == dislike.end()) {
            dislike[i[1]] = vector<int>();
        }
        dislike[i[1]].emplace_back(i[0]);
    }
    
    for (int i = 1; i <= n; i ++) {
        if (!canGroup) {
            return false;
        }
        if (grouped[i] == -1) {
            helper(i, 0, grouped, dislike);
        }
    }
    
    return canGroup;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> dislikes = {{1,6},{7,42},{46,49},{17,46},{32,35},{11,48},{37,48},{37,43},{8,41},{16,22},{41,43},{11,27}};
    std::cout << possibleBipartition(50, dislikes) << "\n";
    return 0;
}

// time: O(dislikes.size())
