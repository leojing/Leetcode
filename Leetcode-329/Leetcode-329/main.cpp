//
//  main.cpp
//  Leetcode-329
//
//  Created by Jing Luo on 4/6/22.
//

#include <iostream>
#include <vector>

using namespace std;

int helper(vector<vector<int>>& matrix, int m, int n, int x, int y, vector<int>& dp) {
    int loc = x * n + y;
    if (dp[loc] > 1) {
        return dp[loc];
    }
    int dir[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        if (newX < 0 || newY < 0 || newX >= m || newY >= n || matrix[newX][newY] <= matrix[x][y]) continue;
        int path = helper(matrix, m, n, newX, newY, dp) + 1;
        dp[loc] = max(dp[loc], path);
    }
    return dp[loc];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<int> dp(m*n, 1);
    int result = INT_MIN;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            int path = helper(matrix, m, n, i, j, dp);
            result = max(result, path);
        }
    }
    return result;
}



int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{0},{1},{5},{5}};//{{3,4,5,3,4,5},{23,4,5,8,2,1}};//{{9,9,4},{6,6,8},{2,1,1}};
    std::cout << longestIncreasingPath(matrix) << "\n";
    return 0;
}
