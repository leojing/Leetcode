//
//  main.cpp
//  Leetcode-240
//
//  Created by Jing Luo on 3/31/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1:
bool helper(vector<int>& nums, int target, int start, int end) {
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (nums[start] == target || nums[end] == target) {
        return true;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0, col = n-1;
    for (int i = 0; i < m; i ++) {
        if (matrix[i][0] <= target && matrix[i][col] >= target) {
            row = i;
            break;
        }
    }
    
    while (row < m && col >= 0) {
        bool find = helper(matrix[row], target, 0, col);
        if (find) {
            return true;
        }
        if (matrix[row][col] > target) {
            col --;
        }
        row ++;
    }
   return false;
}*/

// Solution 2: time: O(n+m), space: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = m ? matrix[0].size() : 0;
    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (matrix[r][c] == target) {
            return true;
        }
        matrix[r][c] > target ? c-- : r++; // search from top-right, and shrink the range
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{-1}, {-1}};
    std::cout << searchMatrix(matrix, 0) << "\n";
    return 0;
}
