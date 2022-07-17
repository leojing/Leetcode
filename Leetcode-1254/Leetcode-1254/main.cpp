//
//  main.cpp
//  Leetcode-1254
//
//  Created by Jing Luo on 7/17/22.
//

#include <iostream>
#include <vector>

using namespace std;

void floodLand(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 1;
    int dir[8] = {0,1,0,-1,1,0,-1,0};
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == 1) {
            continue;
        }
        floodLand(grid, newX, newY);
    }
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    // MARK top and bottom Lands to Water
    for (int i = 0; i < n; i ++) {
        if (grid[0][i] == 0) {
            floodLand(grid, 0, i);
        }
        if (grid[m-1][i] == 0) {
            floodLand(grid, m-1, i);
        }
    }
    // MARK left and right Lands to Water
    for (int i = 0; i < m; i ++) {
        if (grid[i][0] == 0) {
            floodLand(grid, i, 0);
        }
        if (grid[i][n-1] == 0) {
            floodLand(grid, i, n-1);
        }
    }

    int result = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == 0) {
                result ++;
                floodLand(grid, i, j);
            }
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    std::cout << closedIsland(grid) << "\n";
    return 0;
}

// time: O(m*n), space: O(m*n), DFS stack 深度 需要的内存
