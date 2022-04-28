//
//  main.cpp
//  Leetcode-36
//
//  Created by Jing Luo on 4/29/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isValidMiniSudoku(vector<vector<char>>& board, int x, int y) {
    vector<int> exist(9);
    for (int i = x; i < 3 + x; i ++) {
        for (int j = y; j < 3 + y; j ++) {
            if (board[i][j] == '.') { continue; }
            int num = board[i][j] - '0';
            if (find(exist.begin(), exist.end(), num) != exist.end()) { return false; }
            exist.emplace_back(num);
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> exist(9);
    // rows
    for (int i = 0; i < 9; i ++) {
        exist.clear();
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] == '.') { continue; }
            int num = board[i][j] - '0';
            if (find(exist.begin(), exist.end(), num) != exist.end()) { return false; }
            exist.emplace_back(num);
        }
    }
    
    // colums
    for (int i = 0; i < 9; i ++) {
        exist.clear();
        for (int j = 0; j < 9; j ++) {
            if (board[j][i] == '.') { continue; }
            int num = board[j][i] - '0';
            if (find(exist.begin(), exist.end(), num) != exist.end()) { return false; }
            exist.emplace_back(num);
        }
    }


    // 3x3 matrix
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!isValidMiniSudoku(board, i, j)) { return false; }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {{"5","3",".",".","7",".",".",".","."}
        ,{"6",".",".","1","9","5",".",".","."}
        ,{".","9","8",".",".",".",".","6","."}
        ,{"8",".",".",".","6",".",".",".","3"}
        ,{"4",".",".","8",".","3",".",".","1"}
        ,{"7",".",".",".","2",".",".",".","6"}
        ,{".","6",".",".",".",".","2","8","."}
        ,{".",".",".","4","1","9",".",".","5"}
        ,{".",".",".",".","8",".",".","7","9"}};
    
    std::cout << isValidSudoku(board) << "\n";
    return 0;
}
