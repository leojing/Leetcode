//
//  main.cpp
//  Leetcode-419
//
//  Created by Jing Luo on 3/27/22.
//

#include <iostream>
#include <vector>

using namespace std;

int countBattleships(vector<vector<char>>& board) {
    int m = (int)board.size();
    int n = (int)board[0].size();
    int result = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (board[i][j] == 'X') {
                if (i > 0 && board[i-1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j-1] == 'X') {
                    continue;
                }
                result ++;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {{'x','o','o','x'},{'o','o','o','x'},{'o','o','o','x'},{'o','o','o','o'}};
    std::cout << countBattleships(board) << "\n";
    return 0;
}


// time: O(n*m), space: O(1) and not modifying the values board
