//
//  main.cpp
//  Leetcode-417
//
//  Created by Jing Luo on 8/25/21.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>>& heights, vector<int>& record, int x, int y) {
    int m = (int)heights.size();
    int n = (int)heights[0].size();
    record[x*n + y] = 1;
    vector<int> dir = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < (int)dir.size(); i += 2) {
        int newX = x+dir[i];
        int newY = y+dir[i+1];
        if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
            continue;
        }
        if (record[newX*n + newY] == 0 && heights[x][y] <= heights[newX][newY]) {
            helper(heights, record, newX, newY);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> result;
    int m = (int)heights.size();
    int n = (int)heights[0].size();
    vector<int> pacific(n*m);
    vector<int> atlantic(n*m);
    for (int i = 0; i < n; i ++) {
        helper(heights, pacific, 0, i);
        helper(heights, atlantic, m-1, i);
    }
    for (int i = 0; i < m; i ++) {
        helper(heights, pacific, i, 0);
        helper(heights, atlantic, i, n-1);
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (pacific[i*n+j] && atlantic[i*n+j]) {
                result.push_back({i,j});
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}}; //{{2,1},{1,2}};
    vector<vector<int>> result = pacificAtlantic(heights);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 DFS, 但是有个小技巧，不需要一个一个点找过来，会超时，只需要从四个边开始找，看水能没过哪些点，同时被两个海没过的点即为答案
 time：O(n*m), space: O(n*m)
 */
