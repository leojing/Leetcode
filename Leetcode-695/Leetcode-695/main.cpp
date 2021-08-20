//
//  main.cpp
//  Leetcode-695
//
//  Created by Jing Luo on 8/19/21.
//

#include <iostream>
#include <vector>

using namespace std;

int helper(vector<vector<int>>& grid, vector<int>& flag, int n, int m, int x, int y) {
    if (x < 0 ||  x >= n || y < 0 || y >= m) {
        return 0;
    }
    int loc = x * m + y;
    if (flag[loc]) {
        return 0;
    }
    if (grid[x][y] == 0) {
        return 0;
    }
    flag[loc] = 1;
    return 1 + helper(grid, flag, n, m, x+1, y) + helper(grid, flag, n, m, x, y+1) + helper(grid, flag, n, m, x-1, y) + helper(grid, flag, n, m, x, y-1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    if (n == 0) {
        return 0;
    }
    int m = (int)grid[0].size();
    vector<int> flag(n*m, 0);
    int result = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 1) {
                int area = helper(grid, flag, n, m, i, j);
                if (area > result) {
                    result = area;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid =  {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};// {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}}; //
    std::cout << maxAreaOfIsland(grid) << "\n";
    return 0;
}


/*
 time: O(n*m), we visit every square once; space: O(n*m), flag need (n*m) space
 */
