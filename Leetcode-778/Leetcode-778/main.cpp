//
//  main.cpp
//  Leetcode-778
//
//  Created by JINGLUO on 26/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

bool hasPath(std::vector<std::vector<int>>& grid, int n, int i, int j, int time, std::vector<std::vector<int>> visited) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    }
    if (visited[i][j] || grid[i][j] > time) {
        visited[i][j] = true;
        return false;
    }
    if (i == n - 1 && j == n - 1) {
        return true;
    }
    
    visited[i][j] = true;
    std::vector<std::vector<int>> dires = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    for (int k = 0; k < dires.size(); k ++) {
        int newX = i + dires[k][0];
        int newY = j + dires[k][1];
        if (hasPath(grid, n, newX, newY, time, visited)) {
            return true;
        }
    }
    return false;
}

int swimInWater(std::vector<std::vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    
    int n = int(grid[0].size());
    int start = grid[0][0];
    int end = n * n - 1;
    std::vector<std::vector<int>> visited(n, std::vector<int>(n));
    if (hasPath(grid, n, 0, 0, grid[n-1][n-1], visited)) {
        return grid[n-1][n-1];
    }
    while (start < end) {
        int mid = start + (end - start) / 2;
        std::vector<std::vector<int>> visited(n, std::vector<int>(n));
        if (hasPath(grid, n, 0, 0, mid, visited)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::vector<int>> grid = //{{0,3},{1,2}};
//    {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    //{{}};
    //{{0,2},{1,3}};
    {{31,28,33,0,8,57,86,99,23,98},{25,90,20,73,34,65,29,9,42,46},{17,84,10,4,40,5,41,21,71,79},{13,70,69,81,63,93,77,1,94,53},{38,87,61,50,92,2,15,95,82,68},{44,72,88,47,27,91,37,48,83,16},{3,30,96,66,7,58,76,54,19,64},{85,45,60,11,51,26,6,22,74,32},{43,12,62,59,89,52,36,97,49,78},{75,24,14,67,56,35,55,39,80,18}};
    std::cout << swimInWater(grid) << "\n";
    return 0;
}
