//
//  main.cpp
//  Leetcode-1277
//
//  Created by Jing Luo on 4/22/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* solution 1: 暴力枚举
int helper(vector<vector<int>>& matrix, int x, int y, int m, int n) {
    int len = min(m-x-1, n-y-1);
    int result = 1;
    for (int i = 1; i <= len; i ++) {
        for (int j = y; j <= y+i; j ++) {
            if (matrix[x+i][j] == 0) {
                return result;
            }
        }
        for (int j = x; j <= x+i; j ++) {
            if (matrix[j][y+i] == 0) {
                return result;
            }
        }
        result ++;
    }
    return result;
}

int countSquares(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    int result = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (matrix[i][j] == 1) {
                result += helper(matrix, i, j, m, n);
            }
        }
    }
    return result;
}*/

int countSquares(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    int result = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i > 0 && j > 0 && matrix[i][j] > 0) {
                matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
            }
            result += matrix[i][j];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,0,1},{1,1,1,1},{1,0,1,0}};
    std::cout << countSquares(matrix) << "\n";
    return 0;
}
