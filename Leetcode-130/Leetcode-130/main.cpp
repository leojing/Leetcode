//
//  main.cpp
//  Leetcode-130
//
//  Created by Jing Luo on 10/6/21.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int m, int n, int x, int y) {
    board[x][y] = '*';
    int dict[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 7; i += 2) {
        int newX = x + dict[i];
        int newY = y + dict[i+1];
        if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
            continue;;
        }
        if (board[newX][newY] == 'X' || board[newX][newY] == '*') {
            continue;;
        }
        dfs(board, m, n, newX, newY);
    }
}

void solve(vector<vector<char>>& board) {
    int m = (int)board.size();
    int n = (int)board[0].size();
    // mark all 'O' from 4 border
    for (int i = 0; i < m; i ++) {
        if (board[i][0] == 'O') {
            dfs(board, m, n, i, 0);
        }
        if (board[i][n-1] == 'O') {
            dfs(board, m, n, i, n-1);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (board[0][i] == 'O') {
            dfs(board, m, n, 0, i);
        }
        if (board[m-1][i] == 'O') {
            dfs(board, m, n, m-1, i);
        }
    }
    // change all 'O' left to 'X', and meanwile change '*' back to 'O'
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {{'O','X','O'},{'X','O','X'},{'O','X','O'}};
    //{{'X','O','X'},{'X','O','X'},{'X','O','X'}};
    //{{'O','O'},{'O','O'}}; //{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);
    std::cout << "\n";
    return 0;
}


/* Test cases:
 {{'O','O'},
  {'O','O'}}
 
 {{'X','O','X'},
  {'X','O','X'},
  {'X','O','X'}}
 
 {{'X','X','X','X'},
  {'X','O','O','X'},
  {'X','X','O','X'},
  {'X','O','X','X'}}
 
 time复杂度：O(n*m)，其中 n 和 m 分别为矩阵的行数和列数。深度优先搜索过程中，每一个点至多只会被标记一次。
 space复杂度：O(n*m)，其中 n 和 m 分别为矩阵的行数和列数。主要为深度优先搜索的栈的开销。
 */
