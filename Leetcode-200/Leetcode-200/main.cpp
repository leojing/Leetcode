//
//  main.cpp
//  Leetcode-200
//
//  Created by Jing Luo on 3/23/22.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<char>>& grid, int n, int m, int x, int y) {
    grid[x][y] = '0';
    int dir[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
            continue;
        }
        if (grid[newX][newY] == '0') {
            continue;
        }
        helper(grid, n, m, newX, newY);
    }
}
    
int numIslands(vector<vector<char>>& grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    int result = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '1') {
                result += 1;
                helper(grid, n, m, i, j);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}};
    std::cout << numIslands(grid) << "\n";
    return 0;
}
