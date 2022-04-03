//
//  main.cpp
//  Leetcode-42
//
//  Created by Jing Luo on 4/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*   TLE, time: O(n*n), space: O(1)
int trap(vector<int>& height) {
    int start;
    int currHighestIndex = -1;
    int currHighest = 0;
    int currResult = 0;
    int tempResult = 0;
    int result = 0;
    int n = (int)height.size();
    for (int i = 0; i < n; i ++) {
        if (height[i] > 0 && i < n-1) {
            start = i;
            currHighest = 0;
            currResult = 0;
            tempResult = 0;
            ++i;
            while (i < n && height[i] <= height[start]) {
                tempResult += abs(height[start] - height[i]);
                if (height[i] > currHighest) {
                    currHighest = height[i];
                    currHighestIndex = i;
                    currResult = tempResult;
                }
                i ++;
            }
            if (i < n) {
                result += tempResult;
                i -= 1;
            } else {
                result += currResult - abs(height[start] - currHighest);
                i = currHighestIndex - 1;
            }
         }
    }
    return result;
}*/


/*  TLE
int trap(vector<int>& height) {
    int maxLeft, maxRight, result = 0;
    for (int i = 1; i < height.size()-1; i ++) {
        maxLeft = 0;
        maxRight = 0;
        for (int l = i; l >= 0; l --) {
            maxLeft = max(maxLeft, height[l]);
        }
        for (int l = i; l < height.size(); l ++) {
            maxRight = max(maxRight, height[l]);
        }
        result += max(min(maxLeft, maxRight) - height[i], 0);
    }
    return result;
} */

// 改良，用dp去保存leftMax和rightMax，避免O(n*n)的时间复杂度，牺牲O(1)的空间复杂度为O(n)
int trap(vector<int>& height) {
    int result = 0, n = (int)height.size();
    if (n == 0) return 0;
    vector<int> maxLeft(n), maxRight(n);
    maxLeft[0] = height[0];
    for (int i = 1; i < n; i ++) {
        maxLeft[i] = max(maxLeft[i-1], height[i]);
    }
    maxRight[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i --) {
        maxRight[i] = max(maxRight[i+1], height[i]);
    }
    
    for (int i = 0; i < n; i ++) {
        result += min(maxLeft[i], maxRight[i]) - height[i];
    }
    return result;
}

int trap1(vector<int>& height) {
    int left = 0, right = (int)height.size() - 1; //left和right 都表示数组的下标
    int ans = 0;
    int left_max = 0, right_max = 0;   //left_max 和right_max 表示存档的最大值
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans +=      (left_max - height[left]);  //找左边第一个最高的柱子，之后高度不变，直到找到比当前高的再更新
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);   //找右边第一个最高的柱子，之后高度不变，直到找到比当前高的再更新
            --right;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap(height) << "\n";
    return 0;
}
