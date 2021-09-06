//
//  main.cpp
//  Leetcode-52
//
//  Created by Jing Luo on 9/6/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool isValid(int row, int col, vector<vector<int>>& queens) {
    int n = (int)queens.size();
    for (int i = 0; i < row; i ++) {
        // same col, 90 degree
        if (queens[i][col]) {
            return false;
        }
        // 45 degree
        if (row - i - 1 >= 0 && col + i + 1 < n && queens[row - i - 1][col + i + 1]) {
            return false;
        }
        // 135 degree
        if (row - i - 1 >= 0 && col - i - 1 >= 0 && queens[row - i - 1][col - i - 1]) {
            return false;
        }
    }
    return true;
}

void dfs(int n, int row, int& result, vector<vector<int>>& queens) {
    if (row == n) {
        result += 1;
    }
    for (int i = 0; i < n; i ++) {
        if (isValid(row, i, queens)) {
            queens[row][i] = 1;
            dfs(n, row+1, result, queens);
            queens[row][i] = 0;
        }
    }
}

int totalNQueens(int n) {
    if (n == 1) {
        return 1;
    }
    int result = 0;
    vector<vector<int>> queens(n, vector<int>(n, 0));
    dfs(n, 0, result, queens);
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << totalNQueens(4) << "\n";
    return 0;
}


/*
 Time Complexity : O(N!), we have N choices in the first row, N-1 in the second row, N-2 in the next and so on... which brings overall time complexity to O(N!)
 Space Complexity : O(N*N). Required for board and recursive stack.,可以通过将同一斜线上的点用一维数组标记，将空间复杂度降低到O(N)
 */
