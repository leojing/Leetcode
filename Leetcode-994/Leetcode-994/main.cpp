//
//  main.cpp
//  Leetcode-994
//
//  Created by Jing Luo on 8/9/20.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int integrate(int x, int y, int m) {
    return x*m+y; // 这里是m，不是n，容易搞错
}

int getX(int num, int m) {
    return num/m;
}

int getY(int num, int m) {
    return num%m;
}

int orangesRotting(vector<vector<int>>& grid) {
    queue<int> rotten;
    int n = int(grid.size());
    if (n == 0) {
        return 0;
    }
    int count = 0;
    int m = int(grid[0].size());
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 2) {
                rotten.push(integrate(i, j, m));
                count ++;
            }
        }
    }
    int dir[8] = {-1,0,1,0,0,-1,0,1};
    int result = 0;
    // 类似BFS求level
    while (!rotten.empty()) {
        int temp = 0;
        while (count --) {
            int current = rotten.front();
            int currentX = getX(current, m);
            int currentY = getY(current, m);
            for (int i = 0; i < 8; i += 2) {
                int newX = currentX + dir[i];
                int newY = currentY + dir[i+1];
                if (newX < 0 || newX >= n) {
                    continue;
                }
                if (newY < 0 || newY >= m) {
                    continue;
                }
                if (grid[newX][newY] == 1) {
                    temp ++;
                    grid[newX][newY] = 2;
                    rotten.push(integrate(newX, newY, m));
                }
            }
            rotten.pop();
        }
        count = temp;
        result ++;
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return result-1 > 0 ? result-1 : 0;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    //{{2,1,1},{0,1,1},{1,0,1}};
    //{{2,2,2,1,1}};
    std::cout << orangesRotting(grid) << "\n";
    return 0;
}



/*
 ###算法
 BFS
 
 ###代码实现
 ***有什么要注意的地方
 参照代码，已注释
 ***有什么要优化的地方
 
 ###时空复杂度
 time: O(n*m)
 space: O(n*m)
 
 ###相关的题目有哪些
 
 */
