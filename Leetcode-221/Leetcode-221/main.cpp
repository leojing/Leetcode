//
//  main.cpp
//  Leetcode-221
//
//  Created by Jing Luo on 1/18/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = (int)matrix.size(), n = (int)matrix[0].size(), max_side = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); // dp[i][j] 代表坐标点(i,j)为正方形右下角的正方形边长；
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (matrix[i-1][j-1] == '1') { // 这里有点tricky的地方时下面的计算为了方便i-1/j-1，将i，j从1，1开始算，但是dp[1][1]即可以理解为是坐标(0,0)的边长，这样就省去了将边界上的点特殊处理的麻烦
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                max_side = max(max_side, dp[i][j]);
            }
        }
    }
    return max_side * max_side;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::cout << maximalSquare(matrix) << "\n";
    return 0;
}
