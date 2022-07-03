//
//  main.cpp
//  Leetcode-2319
//
//  Created by Jing Luo on 7/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isInDiagonals(vector<vector<int>>& grid, int x, int y) {
    int n = grid.size();
    if (x == y) {
        return true;
    }
    if (x + y == n-1) {
        return true;
    }
    return false;
}

bool checkXMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (isInDiagonals(grid, i , j) && grid[i][j] == 0) {
                return false;
            }
            if (!isInDiagonals(grid, i , j) && grid[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
    std::cout << checkXMatrix(grid) << "\n";
    return 0;
}
