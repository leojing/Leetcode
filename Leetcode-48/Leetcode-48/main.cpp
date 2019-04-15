//
//  main.cpp
//  Leetcode-48
//
//  Created by JINGLUO on 15/4/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n/2; i ++) {
        for(int j = 0; j < n-1-2*i ; j ++)
        {
            swap(matrix[i][j+i],matrix[i+j][n-1-i]);
            swap(matrix[i][j+i],matrix[n-1-i][n-1-i-j]);
            swap(matrix[i][j+i],matrix[n-1-i-j][i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(matrix);
    return 0;
}
