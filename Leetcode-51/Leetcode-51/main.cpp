//
//  main.cpp
//  Leetcode-51
//
//  Created by Jing Luo on 6/3/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

/*
   (0,0) | (0,1) | (0,2)
   (1,0) | (1,1) | (1,2)
   (2,0) | (2,1) | (2,2)
   
   核心：左对角线上的点，横纵坐标和相同；右对角线上的点，横纵坐标差相同
   N queens - 横竖，两个斜对角线上都不能有其他Queen
   */

using namespace std;

vector<vector<string>> result;

void dfs(int n, int x, map<int, bool> &col, map<int, bool> &sum, map<int, bool> &diff, vector<string> &queens) {
    if (x == n) {
        result.push_back(queens);
        return;
    }
    
    for (int i = 0; i < n; i ++) {
        if (col[i] == 1 || sum[x+i] == 1 || diff[x-i] == 1) {
            continue;
        }
        col[i] = 1;
        sum[x+i] = 1;
        diff[x-i] = 1;
        queens[x][i] = 'Q';
        dfs(n, x+1, col, sum, diff, queens);
        col[i] = 0;
        sum[x+i] = 0;
        diff[x-i] = 0;
        queens[x][i] = '.';
    }
}

vector<vector<string>> solveNQueens(int n) {
    if (n == 0) {
        return {{}};
    }
    map<int, bool> visited, sum, diff;
    vector<string> queens(n, string(n, '.'));
    dfs(n, 0, visited, sum, diff, queens);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> result = solveNQueens(4);
    std::cout << "\n";
    return 0;
}
