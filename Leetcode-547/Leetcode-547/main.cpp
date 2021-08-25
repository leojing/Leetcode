//
//  main.cpp
//  Leetcode-547
//
//  Created by Jing Luo on 8/23/21.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
int findCircleNum(vector<vector<int>>& isConnected) {
    int result = 0;
    int n = (int)isConnected.size();
    int m = (int)isConnected[0].size();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (isConnected[i][j] == 1) {
                result ++;
                stack<pair<int, int>> island;
                island.push({i,j});
                isConnected[i][j] = 2;
                while (!island.empty()) {
                    pair<int, int> loc = island.top();
                    island.pop();
                    for (int k = i+1; k < n; k ++) {
                        int x = k;
                        int y = loc.second;
                        if (x >= 0 && x < n && y >= 0 && y < m && isConnected[x][y] == 1) {
                            island.push({x,y});
                            isConnected[x][y] = 2;
                        }
                    }
                    for (int k = j+1; k < m; k ++) {
                        int x = loc.first;
                        int y = k;
                        if (x >= 0 && x < n && y >= 0 && y < m && isConnected[x][y] == 1) {
                            island.push({x,y});
                            isConnected[x][y] = 2;
                        }
                    }
                }
            }
        }
    }
    return result;
}
 */

int findHelper(int x, vector<int> parents) {
    return parents[x] == x ? x : findHelper(parents[x], parents);
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = (int)isConnected.size();
    vector<int> leads(n, 0);
    for (int i = 0; i < n; i ++) {
        leads[i] = i;
    }
    int result = n;
    for (int i = 0; i < n; i ++) {
        for (int j = i+1; j < n; j ++) {
            if (isConnected[i][j]) {
                int findI = findHelper(i, leads);
                int findJ = findHelper(j, leads);
                if (findI != findJ) {
                    leads[findJ] = findI;
                    result --;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> isConnected = {{0,0,0}, {0,0,1}, {0,0,0}};// {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};//{{1,0,0},{0,1,0},{0,0,1}};//{{1,1,0},{1,1,0},{0,0,1}};
    std::cout << findCircleNum(isConnected) << "\n";
    return 0;
}
