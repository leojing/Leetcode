//
//  main.cpp
//  Leetcode-74
//
//  Created by JINGLUO on 25/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1
bool helperCheckRange(std::vector<std::vector<int>>& matrix, int row, int target) {
    int n = int(matrix[row].size());
    if (n == 0) {
        return false;
    }
    return target >= matrix[row][0] && target <= matrix[row][n-1];
}

int searchRows(std::vector<std::vector<int>>& matrix, int start, int end, int target) {
    if (helperCheckRange(matrix, start, target)) {
        return start;
    }
    if (helperCheckRange(matrix, end, target)) {
        return end;
    }
    if (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (helperCheckRange(matrix, mid, target)) {
            return mid;
        }
        if (target < matrix[mid][0]) {
            end = mid;
        } else {
            start = mid;
        }
        return searchRows(matrix, start, end, target);
    }
    return -1;
}

int searchColums(std::vector<std::vector<int>>& matrix, int row, int start, int end, int target) {
    if (target == matrix[row][start]) {
        return start;
    }
    if (target == matrix[row][end]) {
        return end;
    }
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (target == matrix[row][mid]) {
            return mid;
        }
        if (target < matrix[row][mid]) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return -1;
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = int(matrix.size());
    if (m == 0) {
        return false;
    }
    int row = searchRows(matrix, 0, m-1, target);
    if (row == -1) {
        return false;
    }
    int n = int(matrix[row].size());
    if (n == 0) {
        return false;
    }
    int colum = searchColums(matrix, row, 0, n-1, target);
    return colum != -1;
}
 
 */

// Solution 2
int binarySearchForRow(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int start = 0, end = rows - 1;
    while (start + 1 < end) {
        int mid = start + ((end - start) >> 1);
        if (matrix[mid][0] == target) {
            return mid;
        }
        if (matrix[mid][0] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (matrix[start][0] <= target && matrix[end][0] > target) {
        return start;
    }
    if (matrix[end][0] <= target) {
        return end;
    }
    return -1;
}

bool helper(vector<vector<int>>& matrix, int row, int target) {
    int cols = matrix[row].size();
    int start = 0, end = cols - 1;
    while (start + 1 < end) {
        int mid = start + ((end - start) >> 1);
        if (matrix[row][mid] == target) {
            return true;
        }
        if (matrix[row][mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (matrix[row][start] == target || matrix[row][end] == target) {
        return true;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = binarySearchForRow(matrix, target);
    if (row == -1) {
        return false;
    }
    return helper(matrix, row, target);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::vector<int>> matrix =
    {{-10,-10},{-9,-9},{-8,-6},{-4,-2},{0,1},{3,3},{5,5},{6,8}};
    //{{1,3,4,5,7},{10,11,12,16,20},{23,30,34,45,50}};
    //{};
    //{{}};
    std::cout << searchMatrix(matrix, 0) << "\n";
    return 0;
}

/*
 ###算法
 二分法，递归recursion 和 迭代
 
 ###代码实现
 ***有什么要注意的地方
 先搜row，确定target所在的范围的row，再搜colum确定是否存在
 {}, {{}} nil判断一定要优先考虑，因为这个，Runtime error了两把
 
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(log(m+n))  m,n 分别为row 和 colum
 space O(1)
 
 ###相关的题目有哪些
 
 */

