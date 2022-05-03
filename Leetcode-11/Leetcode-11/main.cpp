//
//  main.cpp
//  Leetcode-11
//
//  Created by Jing Luo on 5/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int result = 0;
    while (left < n  && right >= 0 && left < right) {
        int minHeight = min(height[left], height[right]);
        result = max(result, minHeight * (right - left));
        if (height[left] < height[right]) {
            ++ left;
        } else if (height[left] > height[right]) {
            -- right;
        } else {
            ++ left;
            -- right;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(height) << "\n";
    return 0;
}

// time: O(n), space: O(1)
