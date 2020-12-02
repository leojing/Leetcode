//
//  main.cpp
//  Leetcode-79
//
//  Created by Jing Luo on 12/2/20.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool helper(vector<vector<char>>& board, int current, string& word, int x, int y, set<int> visited) {
    int col = int(board.size());
    if (col == 0) {
        return false;
    }
    int row = int(board[0].size());
    if (board[x][y] != word[current]) {
        return false;
    }
    visited.insert(x * row + y);
    if (current == word.length()-1) {
        return true;
    }
    int dir[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        if (newX < 0 || newX >= col || newY < 0 || newY >= row) {
            continue;
        }
        int location = newX * row + newY;
        if (visited.find(location) != visited.end()) {
            continue;
        }
        visited.insert(location);
        if (helper(board, current+1, word, newX, newY, visited)) {
            return true;
        }
        visited.erase(location);
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[i].size(); j ++) {
            set<int> visited;
            int current = 0;
            if (helper(board, current, word, i, j, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word = "ABCESEEEFS";
    std::cout << exist(board, word) << "\n";
    return 0;
}


/*
 // DFS, 如果用current是当前拼接的string会TLE，把current改成word对应的字母位置，遇到不同的马上结束进行剪枝，就可以AC，但是很慢, if pass paramater by value instead of passing by reference, it might be faster, like board and word here
 
 Time: O(n * m * 4^L), L = length of longest word
 Space: O(n * m), size of visited
 
 
 The time complexity will be 𝑂(𝑚∗𝑛∗4^𝑠) where m is the no. of rows and n is the no. of columns in the 2D matrix and s is the length of the input string.

 When we start searching from a character we have 4 choices of neighbors for the first character and subsequent characters have only 3 or less than 3 choices but we can take it as 4 (permissible slopiness in upper bound). This slopiness would be fine in large matrices. So for each character we have 4 choices. Total no. of characters are 𝑠 where s is the length of the input string. So one invocation of search function of your implementation would take 𝑂(4𝑠) time.

 Also in worst case the search is invoked for 𝑚∗𝑛 times. So an upper bound would be 𝑂(𝑚∗𝑛∗4𝑠).
 */
