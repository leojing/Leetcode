//
//  main.cpp
//  Leetcode-934
//
//  Created by Jing Luo on 9/6/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// DFS，找到island1周边的水域，即为起始点，step=1
void dfs(vector<vector<int>>& grid, int n, int m, int x, int y, queue<pair<int, int>>& q, map<int, int>& visited) {
    grid[x][y] = 2;
    int dir[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
            continue;
        }
        if (grid[newX][newY] == 1) {
            dfs(grid, n, m, newX, newY, q, visited);
        }
        if (grid[newX][newY] == 0) {
            q.push(make_pair(newX*m+newY, 1));
            visited[newX*m+newY] = 1;
        }
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    map<int, int> visited;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            visited[i*m+j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i ++) {
        int flag = 0;
        for (int j = 0; j < m; j ++) {
            if (grid[i][j]) {
                flag = 1;
                dfs(grid, n, m, i, j, q, visited);
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    
    // BFS，通过起始点水域，向外延伸，每次step+1，直到找到island1，取最小步数
    int result = INT_MAX;
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        int dir[8] = {0,1,1,0,0,-1,-1,0};
        int x = temp.first/m, y = temp.first%m;
        for (int i = 0; i < 8; i += 2) {
            int newX = x + dir[i];
            int newY = y + dir[i+1];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
                continue;
            }
            if (grid[newX][newY] == 1) {
                result = min(result, visited[x*m+y]);
            } else if (grid[newX][newY] == 0) {
                if (temp.second + 1 < visited[newX*m+newY]) {
                    visited[newX*m+newY] = temp.second + 1;
                    q.push(make_pair(newX*m+newY, temp.second + 1));
                }
            }
        }
        q.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};//{{0,1,0},{0,0,0},{0,0,1}};
    std::cout << shortestBridge(grid) << "\n";
    return 0;
}

/*
 time: O(M*N), space: O(M*N)
 */
